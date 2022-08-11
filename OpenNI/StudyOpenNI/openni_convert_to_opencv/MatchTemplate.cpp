// https://www.bilibili.com/video/BV1Hi4y1u7SH

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/hal/hal.hpp>

using namespace cv;
static void _crossCorr(const Mat& img, const Mat& _templ, Mat& corr,
    Point anchor, double delta, int borderType)
{
    const double blockScale = 4.5;
    const int minBlockSize = 256;
    std::vector<uchar> buf;

    Mat templ = _templ;
    int depth = img.depth(), cn = img.channels();
    int tdepth = templ.depth(), tcn = templ.channels();
    int cdepth = corr.depth(), ccn = corr.channels();

    CV_Assert(img.dims <= 2 && templ.dims <= 2 && corr.dims <= 2);

    if (depth != tdepth && tdepth != std::max(CV_32F, depth))
    {
        _templ.convertTo(templ, std::max(CV_32F, depth));
        tdepth = templ.depth();
    }

    CV_Assert(depth == tdepth || tdepth == CV_32F);
    CV_Assert(corr.rows <= img.rows + templ.rows - 1 &&
        corr.cols <= img.cols + templ.cols - 1);

    CV_Assert(ccn == 1 || delta == 0);

    int maxDepth = depth > CV_8S ? CV_64F : std::max(std::max(CV_32F, tdepth), cdepth);
    Size blocksize, dftsize;

    blocksize.width = cvRound(templ.cols * blockScale);
    blocksize.width = std::max(blocksize.width, minBlockSize - templ.cols + 1);
    blocksize.width = std::min(blocksize.width, corr.cols);
    blocksize.height = cvRound(templ.rows * blockScale);
    blocksize.height = std::max(blocksize.height, minBlockSize - templ.rows + 1);
    blocksize.height = std::min(blocksize.height, corr.rows);

    dftsize.width = std::max(getOptimalDFTSize(blocksize.width + templ.cols - 1), 2);
    dftsize.height = getOptimalDFTSize(blocksize.height + templ.rows - 1);
    //if( dftsize.width <= 0 || dftsize.height <= 0 )
        //CV_Error( StsOutOfRange, "the input arrays are too big" );

    // recompute block size
    blocksize.width = dftsize.width - templ.cols + 1;
    blocksize.width = MIN(blocksize.width, corr.cols);
    blocksize.height = dftsize.height - templ.rows + 1;
    blocksize.height = MIN(blocksize.height, corr.rows);

    Mat dftTempl(dftsize.height * tcn, dftsize.width, maxDepth);
    Mat dftImg(dftsize, maxDepth);

    int i, k, bufSize = 0;
    if (tcn > 1 && tdepth != maxDepth)
        bufSize = templ.cols * templ.rows * CV_ELEM_SIZE(tdepth);

    if (cn > 1 && depth != maxDepth)
        bufSize = std::max(bufSize, (blocksize.width + templ.cols - 1) *
            (blocksize.height + templ.rows - 1) * CV_ELEM_SIZE(depth));

    if ((ccn > 1 || cn > 1) && cdepth != maxDepth)
        bufSize = std::max(bufSize, blocksize.width * blocksize.height * CV_ELEM_SIZE(cdepth));

    buf.resize(bufSize);

    Ptr<hal::DFT2D> c = hal::DFT2D::create(dftsize.width, dftsize.height, dftTempl.depth(), 1, 1, CV_HAL_DFT_IS_INPLACE, templ.rows);

    // compute DFT of each template plane
    for (k = 0; k < tcn; k++)
    {
        int yofs = k * dftsize.height;
        Mat src = templ;
        Mat dst(dftTempl, Rect(0, yofs, dftsize.width, dftsize.height));
        Mat dst1(dftTempl, Rect(0, yofs, templ.cols, templ.rows));

        if (tcn > 1)
        {
            src = tdepth == maxDepth ? dst1 : Mat(templ.size(), tdepth, &buf[0]);
            int pairs[] = { k, 0 };
            mixChannels(&templ, 1, &src, 1, pairs, 1);
        }

        if (dst1.data != src.data)
            src.convertTo(dst1, dst1.depth());

        if (dst.cols > templ.cols)
        {
            Mat part(dst, Range(0, templ.rows), Range(templ.cols, dst.cols));
            part = Scalar::all(0);
        }
        c->apply(dst.data, (int)dst.step, dst.data, (int)dst.step);
    }

    int tileCountX = (corr.cols + blocksize.width - 1) / blocksize.width;
    int tileCountY = (corr.rows + blocksize.height - 1) / blocksize.height;
    int tileCount = tileCountX * tileCountY;

    Size wholeSize = img.size();
    Point roiofs(0, 0);
    Mat img0 = img;

    if (!(borderType & BORDER_ISOLATED))
    {
        img.locateROI(wholeSize, roiofs);
        img0.adjustROI(roiofs.y, wholeSize.height - img.rows - roiofs.y,
            roiofs.x, wholeSize.width - img.cols - roiofs.x);
    }
    borderType |= BORDER_ISOLATED;

    Ptr<hal::DFT2D> cF, cR;
    int f = CV_HAL_DFT_IS_INPLACE;
    int f_inv = f | CV_HAL_DFT_INVERSE | CV_HAL_DFT_SCALE;
    cF = hal::DFT2D::create(dftsize.width, dftsize.height, maxDepth, 1, 1, f, blocksize.height + templ.rows - 1);
    cR = hal::DFT2D::create(dftsize.width, dftsize.height, maxDepth, 1, 1, f_inv, blocksize.height);

    // calculate correlation by blocks
    for (i = 0; i < tileCount; i++)
    {
        int x = (i % tileCountX) * blocksize.width;
        int y = (i / tileCountX) * blocksize.height;

        Size bsz(std::min(blocksize.width, corr.cols - x),
            std::min(blocksize.height, corr.rows - y));
        Size dsz(bsz.width + templ.cols - 1, bsz.height + templ.rows - 1);
        int x0 = x - anchor.x + roiofs.x, y0 = y - anchor.y + roiofs.y;
        int x1 = std::max(0, x0), y1 = std::max(0, y0);
        int x2 = std::min(img0.cols, x0 + dsz.width);
        int y2 = std::min(img0.rows, y0 + dsz.height);
        Mat src0(img0, Range(y1, y2), Range(x1, x2));
        Mat dst(dftImg, Rect(0, 0, dsz.width, dsz.height));
        Mat dst1(dftImg, Rect(x1 - x0, y1 - y0, x2 - x1, y2 - y1));
        Mat cdst(corr, Rect(x, y, bsz.width, bsz.height));

        for (k = 0; k < cn; k++)
        {
            Mat src = src0;
            dftImg = Scalar::all(0);

            if (cn > 1)
            {
                src = depth == maxDepth ? dst1 : Mat(y2 - y1, x2 - x1, depth, &buf[0]);
                int pairs[] = { k, 0 };
                mixChannels(&src0, 1, &src, 1, pairs, 1);
            }

            if (dst1.data != src.data)
                src.convertTo(dst1, dst1.depth());

            if (x2 - x1 < dsz.width || y2 - y1 < dsz.height)
                copyMakeBorder(dst1, dst, y1 - y0, dst.rows - dst1.rows - (y1 - y0),
                    x1 - x0, dst.cols - dst1.cols - (x1 - x0), borderType);

            if (bsz.height == blocksize.height)
                cF->apply(dftImg.data, (int)dftImg.step, dftImg.data, (int)dftImg.step);
            else
                dft(dftImg, dftImg, 0, dsz.height);

            Mat dftTempl1(dftTempl, Rect(0, tcn > 1 ? k * dftsize.height : 0,
                dftsize.width, dftsize.height));
            mulSpectrums(dftImg, dftTempl1, dftImg, 0, true);

            if (bsz.height == blocksize.height)
                cR->apply(dftImg.data, (int)dftImg.step, dftImg.data, (int)dftImg.step);
            else
                dft(dftImg, dftImg, DFT_INVERSE + DFT_SCALE, bsz.height);

            src = dftImg(Rect(0, 0, bsz.width, bsz.height));

            if (ccn > 1)
            {
                if (cdepth != maxDepth)
                {
                    Mat plane(bsz, cdepth, &buf[0]);
                    src.convertTo(plane, cdepth, 1, delta);
                    src = plane;
                }
                int pairs[] = { 0, k };
                mixChannels(&src, 1, &cdst, 1, pairs, 1);
            }
            else
            {
                if (k == 0)
                    src.convertTo(cdst, cdepth, 1, delta);
                else
                {
                    if (maxDepth != cdepth)
                    {
                        Mat plane(bsz, cdepth, &buf[0]);
                        src.convertTo(plane, cdepth);
                        src = plane;
                    }
                    add(src, cdst, cdst);
                }
            }
        }
    }
}

static void _matchTemplateMask(InputArray _img, InputArray _templ, OutputArray _result, int method, InputArray _mask)
{
    int type = _img.type(), depth = CV_MAT_DEPTH(type), cn = CV_MAT_CN(type);
    CV_Assert(TM_SQDIFF <= method && method <= TM_CCOEFF_NORMED);
    CV_Assert((depth == CV_8U || depth == CV_32F) && type == _templ.type() && _img.dims() <= 2);

    Mat img = _img.getMat(), templ = _templ.getMat(), mask = _mask.getMat();
    int ttype = templ.type(), tdepth = CV_MAT_DEPTH(ttype), tcn = CV_MAT_CN(ttype);
    int mtype = img.type(), mdepth = CV_MAT_DEPTH(type), mcn = CV_MAT_CN(mtype);

    if (depth == CV_8U)
    {
        depth = CV_32F;
        type = CV_MAKETYPE(CV_32F, cn);
        img.convertTo(img, type, 1.0 / 255);
    }

    if (tdepth == CV_8U)
    {
        tdepth = CV_32F;
        ttype = CV_MAKETYPE(CV_32F, tcn);
        templ.convertTo(templ, ttype, 1.0 / 255);
    }

    if (mdepth == CV_8U)
    {
        mdepth = CV_32F;
        mtype = CV_MAKETYPE(CV_32F, mcn);
        compare(mask, Scalar::all(0), mask, CMP_NE);
        mask.convertTo(mask, mtype, 1.0 / 255);
    }

    Size corrSize(img.cols - templ.cols + 1, img.rows - templ.rows + 1);
    _result.create(corrSize, CV_32F);
    Mat result = _result.getMat();

    Mat img2 = img.mul(img);
    Mat mask2 = mask.mul(mask);
    Mat mask_templ = templ.mul(mask);
    Scalar templMean, templSdv;

    double templSum2 = 0;
    meanStdDev(mask_templ, templMean, templSdv);

    templSum2 = templSdv[0] * templSdv[0] + templSdv[1] * templSdv[1] + templSdv[2] * templSdv[2] + templSdv[3] * templSdv[3];
    templSum2 += templMean[0] * templMean[0] + templMean[1] * templMean[1] + templMean[2] * templMean[2] + templMean[3] * templMean[3];
    templSum2 *= ((double)templ.rows * templ.cols);

    if (method == TM_SQDIFF)
    {
        Mat mask2_templ = templ.mul(mask2);

        Mat corr(corrSize, CV_32F);
        _crossCorr(img, mask2_templ, corr, Point(0, 0), 0, 0);
        _crossCorr(img2, mask, result, Point(0, 0), 0, 0);

        result -= corr * 2;
        result += templSum2;
    }
    else if (method == TM_CCORR_NORMED)
    {
        if (templSum2 < DBL_EPSILON)
        {
            result = Scalar::all(1);
            return;
        }

        Mat corr(corrSize, CV_32F);
        _crossCorr(img2, mask2, corr, Point(0, 0), 0, 0);
        _crossCorr(img, mask_templ, result, Point(0, 0), 0, 0);

        sqrt(corr, corr);
        result = result.mul(1 / corr);
        result /= std::sqrt(templSum2);
    }
    else
        CV_Error(Error::StsNotImplemented, "");
}

static void _common_matchTemplate(Mat& img, Mat& templ, Mat& result, int method, int cn)
{
    if (method == TM_CCORR)
        return;

    int numType = method == TM_CCORR || method == TM_CCORR_NORMED ? 0 :
        method == TM_CCOEFF || method == TM_CCOEFF_NORMED ? 1 : 2;
    bool isNormed = method == TM_CCORR_NORMED ||
        method == TM_SQDIFF_NORMED ||
        method == TM_CCOEFF_NORMED;

    double invArea = 1. / ((double)templ.rows * templ.cols);

    Mat sum, sqsum;
    Scalar templMean, templSdv;
    double* q0 = 0, * q1 = 0, * q2 = 0, * q3 = 0;
    double templNorm = 0, templSum2 = 0;

    if (method == TM_CCOEFF)
    {
        integral(img, sum, CV_64F);
        templMean = mean(templ);
    }
    else
    {
        integral(img, sum, sqsum, CV_64F);
        meanStdDev(templ, templMean, templSdv);

        templNorm = templSdv[0] * templSdv[0] + templSdv[1] * templSdv[1] + templSdv[2] * templSdv[2] + templSdv[3] * templSdv[3];

        if (templNorm < DBL_EPSILON && method == TM_CCOEFF_NORMED)
        {
            result = Scalar::all(1);
            return;
        }

        templSum2 = templNorm + templMean[0] * templMean[0] + templMean[1] * templMean[1] + templMean[2] * templMean[2] + templMean[3] * templMean[3];

        if (numType != 1)
        {
            templMean = Scalar::all(0);
            templNorm = templSum2;
        }

        templSum2 /= invArea;
        templNorm = std::sqrt(templNorm);
        templNorm /= std::sqrt(invArea); // care of accuracy here

        CV_Assert(sqsum.data != NULL);
        q0 = (double*)sqsum.data;
        q1 = q0 + templ.cols * cn;
        q2 = (double*)(sqsum.data + templ.rows * sqsum.step);
        q3 = q2 + templ.cols * cn;
    }

    CV_Assert(sum.data != NULL);
    double* p0 = (double*)sum.data;
    double* p1 = p0 + templ.cols * cn;
    double* p2 = (double*)(sum.data + templ.rows * sum.step);
    double* p3 = p2 + templ.cols * cn;

    int sumstep = sum.data ? (int)(sum.step / sizeof(double)) : 0;
    int sqstep = sqsum.data ? (int)(sqsum.step / sizeof(double)) : 0;

    int i, j, k;

    for (i = 0; i < result.rows; i++)
    {
        float* rrow = result.ptr<float>(i);
        int idx = i * sumstep;
        int idx2 = i * sqstep;

        for (j = 0; j < result.cols; j++, idx += cn, idx2 += cn)
        {
            double num = rrow[j], t;
            double wndMean2 = 0, wndSum2 = 0;

            if (numType == 1)
            {
                for (k = 0; k < cn; k++)
                {
                    t = p0[idx + k] - p1[idx + k] - p2[idx + k] + p3[idx + k];
                    wndMean2 += t * t;
                    num -= t * templMean[k];
                }

                wndMean2 *= invArea;
            }

            if (isNormed || numType == 2)
            {
                for (k = 0; k < cn; k++)
                {
                    t = q0[idx2 + k] - q1[idx2 + k] - q2[idx2 + k] + q3[idx2 + k];
                    wndSum2 += t;
                }

                if (numType == 2)
                {
                    num = wndSum2 - 2 * num + templSum2;
                    num = MAX(num, 0.);
                }
            }

            if (isNormed)
            {
                double diff2 = MAX(wndSum2 - wndMean2, 0);
                if (diff2 <= std::min(0.5, 10 * FLT_EPSILON * wndSum2))
                    t = 0; // avoid rounding errors
                else
                    t = std::sqrt(diff2) * templNorm;

                if (fabs(num) < t)
                    num /= t;
                else if (fabs(num) < t * 1.125)
                    num = num > 0 ? 1 : -1;
                else
                    num = method != TM_SQDIFF_NORMED ? 0 : 1;
            }

            rrow[j] = (float)num;
        }
    }
}

static void _matchTemplate(InputArray _img, InputArray _templ, OutputArray _result, int method, InputArray _mask)
{

    if (!_mask.empty())
    {
        _matchTemplateMask(_img, _templ, _result, method, _mask);
        return;
    }

    int type = _img.type(), depth = CV_MAT_DEPTH(type), cn = CV_MAT_CN(type);
    CV_Assert(TM_SQDIFF <= method && method <= TM_CCOEFF_NORMED);
    CV_Assert((depth == CV_8U || depth == CV_32F) && type == _templ.type() && _img.dims() <= 2);

    bool needswap = _img.size().height < _templ.size().height || _img.size().width < _templ.size().width;
    if (needswap)
    {
        CV_Assert(_img.size().height <= _templ.size().height && _img.size().width <= _templ.size().width);
    }

    Mat img = _img.getMat(), templ = _templ.getMat();
    if (needswap)
        std::swap(img, templ);

    Size corrSize(img.cols - templ.cols + 1, img.rows - templ.rows + 1);
    _result.create(corrSize, CV_32F);
    Mat result = _result.getMat();

    _crossCorr(img, templ, result, Point(0, 0), 0, 0);

    _common_matchTemplate(img, templ, result, method, cn);
}

static int _non_equal_size(const cv::Mat& m1, const cv::Mat& m2) {
    CV_Assert(m1.type() == CV_32FC1);
    CV_Assert(m2.type() == CV_32FC1);

    cv::Mat abs_diff;
    cv::absdiff(m1, m2, abs_diff);
    std::vector<cv::Point> nonzeros;
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            if (abs_diff.ptr<float>(i)[j] > FLT_EPSILON) {
                nonzeros.push_back(cv::Point(j, i));
            }
        }
    }
    return nonzeros.size();
}

static void _template_match_ccorr(const cv::Mat& src, const cv::Mat& templ, cv::Mat& dst) {
    cv::Size dftsize;
    dftsize.width = cv::getOptimalDFTSize(src.cols);
    dftsize.height = cv::getOptimalDFTSize(src.rows);

    cv::Mat dftTempl = cv::Mat::zeros(dftsize, CV_32FC1);
    cv::Mat dftTemplPart(dftTempl, cv::Rect(0, 0, templ.cols, templ.rows));
    templ.convertTo(dftTemplPart, CV_32FC1);
    cv::dft(dftTempl, dftTempl, 0, templ.rows);

    cv::Mat dftSrc(src.size(), CV_32FC1);
    src.convertTo(dftSrc, CV_32FC1);
    cv::copyMakeBorder(dftSrc, dftSrc, 0, dftsize.height - src.rows, 0, dftsize.width - src.cols, 0);
    cv::dft(dftSrc, dftSrc, 0, src.rows);

    cv::mulSpectrums(dftSrc, dftTempl, dftSrc, 0, true);

    cv::dft(dftSrc, dftSrc, cv::DFT_INVERSE + cv::DFT_SCALE, dst.rows);

    cv::Mat part(dftSrc, cv::Rect(0, 0, dst.cols, dst.rows));
    part.convertTo(dst, CV_32FC1);
}

static void _template_match_ccorr_normed(const cv::Mat& src, const cv::Mat& templ, cv::Mat& dst) {
    _template_match_ccorr(src, templ, dst);

    /*
    cv::Mat src_double, templ_double;
    src.convertTo(src_double, CV_64FC1);
    templ.convertTo(templ_double, CV_64FC1);

    cv::Mat templ2;
    cv::multiply(templ_double, templ_double, templ2);
    cv::Scalar s1 = cv::sum(templ2);
    for (int i = 0; i < dst.rows; i++) {
        for (int j = 0; j < dst.cols; j++) {
            cv::Mat submat(src_double, cv::Rect(j, i, templ.cols, templ.rows));
            cv::Mat submat2;
            cv::multiply(submat, submat, submat2);
            cv::Scalar s2 = cv::sum(submat2);
            dst.ptr<float>(i)[j] /= (float)std::sqrt(s1[0]*s2[0]);
        }
    }
    */

    cv::Scalar templMean, templSdv;
    cv::meanStdDev(templ, templMean, templSdv);
    double templNorm = templSdv[0] * templSdv[0] + templMean[0] * templMean[0];
    double area = (double)templ.rows * templ.cols;
    templNorm = std::sqrt(templNorm);
    templNorm *= std::sqrt(area);

    cv::Mat sum, sqsum;
    cv::integral(src, sum, sqsum, CV_64FC1);
    for (int i = 0; i < dst.rows; i++) {
        for (int j = 0; j < dst.cols; j++) {
            double num = dst.ptr<float>(i)[j];
            double wndSum2 = sqsum.ptr<double>(i)[j] - sqsum.ptr<double>(i)[j + templ.cols] - sqsum.ptr<double>(i + templ.rows)[j] + sqsum.ptr<double>(i + templ.rows)[j + templ.cols];
            num /= std::sqrt(wndSum2) * templNorm;
            dst.ptr<float>(i)[j] = (float)num;
        }
    }
}

static void _template_match_sq_diff(const cv::Mat& src, const cv::Mat& templ, cv::Mat& dst) {
    _template_match_ccorr(src, templ, dst);

    cv::Scalar templMean, templSdv;
    cv::meanStdDev(templ, templMean, templSdv);
    double templSum2 = templSdv[0] * templSdv[0] + templMean[0] * templMean[0];
    double area = (double)templ.rows * templ.cols;
    templSum2 *= area;

    cv::Mat sum, sqsum;
    cv::integral(src, sum, sqsum, CV_64FC1);
    for (int i = 0; i < dst.rows; i++) {
        for (int j = 0; j < dst.cols; j++) {
            double num = dst.ptr<float>(i)[j];
            double wndSum2 = sqsum.ptr<double>(i)[j] - sqsum.ptr<double>(i)[j + templ.cols] - sqsum.ptr<double>(i + templ.rows)[j] + sqsum.ptr<double>(i + templ.rows)[j + templ.cols];
            dst.ptr<float>(i)[j] = (float)(templSum2 - 2 * num + wndSum2);
        }
    }
}

static void _template_match_sq_diff_normed(const cv::Mat& src, const cv::Mat& templ, cv::Mat& dst) {
    _template_match_ccorr(src, templ, dst);

    cv::Scalar templMean, templSdv;
    cv::meanStdDev(templ, templMean, templSdv);
    double templSum2 = templSdv[0] * templSdv[0] + templMean[0] * templMean[0];
    double templNorm = templSum2;
    double area = (double)templ.rows * templ.cols;
    templSum2 *= area;
    templNorm = std::sqrt(templNorm);
    templNorm *= std::sqrt(area);

    cv::Mat sum, sqsum;
    cv::integral(src, sum, sqsum, CV_64FC1);
    for (int i = 0; i < dst.rows; i++) {
        for (int j = 0; j < dst.cols; j++) {
            double num = dst.ptr<float>(i)[j];
            double wndSum2 = sqsum.ptr<double>(i)[j] - sqsum.ptr<double>(i)[j + templ.cols] - sqsum.ptr<double>(i + templ.rows)[j] + sqsum.ptr<double>(i + templ.rows)[j + templ.cols];

            num = MAX(templSum2 - 2 * num + wndSum2, 0);

            double diff = MAX(wndSum2, 0);
            double normed = std::sqrt(diff) * templNorm;
            if (diff <= std::min(0.5, 10 * FLT_EPSILON * wndSum2)) {
                normed = 0;
            }

            if (std::fabs(num) < normed) {
                num /= normed;
            }
            else if (std::fabs(num) < normed * 1.125) {
                num = (num > 0 ? 1 : -1);
            }
            else {
                num = 1;
            }

            dst.ptr<float>(i)[j] = (float)num;
        }
    }
}

static void _template_match_ccoeff(const cv::Mat& src, const cv::Mat& templ, cv::Mat& dst) {
    _template_match_ccorr(src, templ, dst);

    cv::Scalar templMean = cv::mean(templ);

    cv::Mat sum;
    cv::integral(src, sum, CV_64FC1);
    for (int i = 0; i < dst.rows; i++) {
        for (int j = 0; j < dst.cols; j++) {
            double num = dst.ptr<float>(i)[j];
            double wndSum = sum.ptr<double>(i)[j] - sum.ptr<double>(i)[j + templ.cols] - sum.ptr<double>(i + templ.rows)[j] + sum.ptr<double>(i + templ.rows)[j + templ.cols];
            num -= wndSum * templMean[0];
            dst.ptr<float>(i)[j] = (float)num;
        }
    }
}

static void _template_match_ccoeff_normed(const cv::Mat& src, const cv::Mat& templ, cv::Mat& dst) {
    _template_match_ccorr(src, templ, dst);

    cv::Scalar templMean, templSdv;
    cv::meanStdDev(templ, templMean, templSdv);
    double templNorm = templSdv[0] * templSdv[0];
    if (templNorm < DBL_EPSILON) {
        dst = cv::Scalar::all(1);
        return;
    }
    double templSum2 = templNorm + templMean[0] * templMean[0];
    double area = (double)templ.rows * templ.cols;
    templSum2 *= area;
    templNorm = std::sqrt(templNorm);
    templNorm *= std::sqrt(area);

    cv::Mat sum, sqsum;
    cv::integral(src, sum, sqsum, CV_64FC1);
    for (int i = 0; i < dst.rows; i++) {
        for (int j = 0; j < dst.cols; j++) {
            double num = dst.ptr<float>(i)[j];
            double wndSum = sum.ptr<double>(i)[j] - sum.ptr<double>(i)[j + templ.cols] - sum.ptr<double>(i + templ.rows)[j] + sum.ptr<double>(i + templ.rows)[j + templ.cols];
            num -= wndSum * templMean[0];

            double wndMean2 = wndSum * wndSum;
            wndMean2 /= area;

            double wndSum2 = sqsum.ptr<double>(i)[j] - sqsum.ptr<double>(i)[j + templ.cols] - sqsum.ptr<double>(i + templ.rows)[j] + sqsum.ptr<double>(i + templ.rows)[j + templ.cols];

            double diff2 = MAX(wndSum2 - wndMean2, 0);
            double normed = std::sqrt(diff2) * templNorm;
            if (diff2 <= std::min(0.5, 10 * FLT_EPSILON * wndSum2)) {
                normed = 0;
            }
            if (std::fabs(num) < normed) {
                num /= normed;
            }
            else if (std::fabs(num) < normed * 1.125) {
                num = (num > 0 ? 1 : -1);
            }
            else {
                num = 0;
            }

            dst.ptr<float>(i)[j] = (float)num;
        }
    }
}

int main(int argc, char** argv) {
    /*
    cv::Mat src = cv::imread("/home/xlll/Downloads/opencv/samples/data/pic1.png", cv::IMREAD_COLOR);
    cv::Mat templ = cv::imread("/home/xlll/Downloads/opencv/samples/data/templ.png", cv::IMREAD_COLOR);
    if (src.empty() || templ.empty()) {
        std::cout << "failed to read image" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> methods = {cv::TM_SQDIFF, cv::TM_SQDIFF_NORMED, cv::TM_CCORR, cv::TM_CCORR_NORMED, cv::TM_CCOEFF, cv::TM_CCOEFF_NORMED};
    std::vector<cv::String> method_names = {"sqdiff", "sqdiff_normed", "ccorr", "ccorr_nomred", "ccoeff", "ccoeff_normed"};

    std::vector<cv::Mat> match_mats(methods.size());
    for (int i = 0; i < methods.size(); i++) {
        cv::Mat& match_mat = match_mats[i];
        cv::matchTemplate(src, templ, match_mat, methods[i]);
    }

    std::vector<cv::Point> match_locations(methods.size());
    for (int i = 0; i < methods.size(); i++) {
        cv::Point pt_min, pt_max;
        cv::minMaxLoc(match_mats[i], NULL, NULL, &pt_min, &pt_max);
        if (methods[i] == cv::TM_SQDIFF || methods[i] == cv::TM_SQDIFF_NORMED) {
            match_locations[i] = pt_min;
        } else {
            match_locations[i] = pt_max;
        }
        std::cout << method_names[i] << " = " << match_locations[i] << std::endl;
    }

    std::vector<cv::Mat> match_normed_mats(methods.size());
    for (int i = 0; i < methods.size(); i++) {
        cv::Mat& match_normed_mat = match_normed_mats[i];
        cv::normalize(match_mats[i], match_normed_mat, 0, 255, cv::NORM_MINMAX);
    }

    std::vector<cv::Mat> dsts(methods.size());
    for (int i = 0; i < methods.size(); i++) {
        cv::Mat& dst = dsts[i];
        src.copyTo(dst);
        cv::Point match_loc = match_locations[i];
        cv::rectangle(dst, cv::Rect(match_loc.x, match_loc.y, templ.cols, templ.rows), cv::Scalar(255, 0, 255), 2, cv::LINE_AA);
    }

    cv::imshow("src", src);
    cv::imshow("templ", templ);
    for (int i = 0; i < methods.size(); i++) {
        cv::imshow(method_names[i], match_normed_mats[i]);
        cv::imshow(method_names[i] + "_dst", dsts[i]);
    }
    cv::waitKey(0);
    */

    cv::Mat src_color = cv::imread("E:/MyGithub/Cpp/OpenNI/StudyOpenNI/openni_convert_to_opencv/redbox2.jpg", cv::IMREAD_COLOR);
    cv::Mat templ = cv::imread("E:/MyGithub/Cpp/OpenNI/StudyOpenNI/openni_convert_to_opencv/redbox1.jpg", cv::IMREAD_GRAYSCALE);
    if (src_color.empty() || templ.empty()) {
        std::cout << "failed to read image" << std::endl;
        return EXIT_FAILURE;
    }

    Size dsize0 = Size(500, 250);
    resize(templ, templ, dsize0, 0, 0);

    cv::Mat src;
    cv::cvtColor(src_color, src, cv::COLOR_BGR2GRAY);

    cv::Mat dst1;
    //cv::matchTemplate(src, templ, dst1, cv::TM_CCORR);

    cv::Mat dst2(src.rows - templ.rows + 1, src.cols - templ.cols + 1, CV_32FC1);
    //_matchTemplate(src, templ, dst2, cv::TM_CCORR, cv::Mat());
    //_matchTemplate(src, templ, dst1, cv::TM_CCORR, cv::Mat());
    //_matchTemplate(src, templ, dst1, cv::TM_CCORR_NORMED, cv::Mat());
    //_matchTemplate(src, templ, dst1, cv::TM_SQDIFF, cv::Mat());
    //_matchTemplate(src, templ, dst1, cv::TM_SQDIFF_NORMED, cv::Mat());
    //_matchTemplate(src, templ, dst1, cv::TM_CCOEFF, cv::Mat());
    _matchTemplate(src, templ, dst1, cv::TM_CCOEFF_NORMED, cv::Mat());
    //_template_match_ccorr(src, templ, dst2);
    //_template_match_ccorr_normed(src, templ, dst2);
    //_template_match_sq_diff(src, templ, dst2);
    //_template_match_sq_diff_normed(src, templ, dst2);
    //_template_match_ccoeff(src, templ, dst2);
    _template_match_ccoeff_normed(src, templ, dst2);

    std::cout << "non equal size = " << _non_equal_size(dst1, dst2) << std::endl;

    cv::Point max_pt_indices1, max_pt_indices2;
    cv::minMaxLoc(dst1, NULL, NULL, NULL, &max_pt_indices1);
    cv::minMaxLoc(dst2, NULL, NULL, NULL, &max_pt_indices2);
    std::cout << "point 1: " << max_pt_indices1 << std::endl;
    std::cout << "point 2: " << max_pt_indices2 << std::endl;

    cv::Mat dst11, dst22;
    src_color.copyTo(dst11);
    src_color.copyTo(dst22);
    cv::rectangle(dst11, cv::Rect(max_pt_indices1.x, max_pt_indices1.y, templ.cols, templ.rows), cv::Scalar(255, 0, 0), 2, cv::LINE_AA);
    cv::rectangle(dst22, cv::Rect(max_pt_indices2.x, max_pt_indices2.y, templ.cols, templ.rows), cv::Scalar(255, 0, 0), 2, cv::LINE_AA);

    cv::normalize(dst1, dst1, 0, 255, cv::NORM_MINMAX);
    cv::normalize(dst2, dst2, 0, 255, cv::NORM_MINMAX);

    //cv::imshow("src", src);
    //cv::imshow("templ", templ);

    Size dsize = Size(600, 300);
    resize(dst1, dst1, dsize, 0, 0);
    resize(dst2, dst2, dsize, 0, 0);
    resize(dst11, dst11, dsize, 0, 0);
    resize(dst22, dst2, dsize, 0, 0);

    //cv::imshow("dst1", dst1);
    //cv::imshow("dst2", dst2);
    cv::imshow("dst11", dst11);
    cv::imshow("dst22", dst22);
    cv::waitKey(0);


    return 0;
}
