// https://docs.opencv.org/4.x/d5/d98/tutorial_mat_operations.html
// ���÷��� 1_4_OperationsWithImages imageName.jpg [G]

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace std;
using namespace cv;

static void help(char* progName)
{
    cout << endl
        << "Usage:" << endl
        << progName << " [image_path -- default lena.jpg] [G -- grayscale] " << endl << endl;
}

int main(int argc, char* argv[])
{
    help(argv[0]);
    const char* filename = argc >= 2 ? argv[1] : "lena.jpg";

    Mat src, dst0, dst1;

    if (argc >= 3 && !strcmp("G", argv[2]))
        src = imread(samples::findFile(filename), IMREAD_GRAYSCALE);
    else
        src = imread(samples::findFile(filename), IMREAD_COLOR);

    if (src.empty())
    {
        cerr << "Can't open image [" << filename << "]" << endl;
        return EXIT_FAILURE;
    }

    // J = imwrite('output.jpg', I);

    //// ��������ֵ
    //// ��ȡ��ͨ���Ҷ�ͼ��8UC1��
    //Scalar intensity = img.at<uchar>(y, x); // ����1
    //Scalar intensity = I.at<uchar>(Point(x, y)); // ����2
    //// ��ȡBGR��ͨ��ͼ
    //Vec3b intensity = img.at<Vec3b>(y, x);
    //uchar blue = intensity.val[0];
    //uchar green = intensity.val[1];
    //uchar red = intensity.val[2];

    // ѡ��ROI
    //Rect r(10, 10, 100, 100);
    //Mat smallImg = img(r);

    // ���ӻ�ͼ��
    namedWindow("output", WINDOW_AUTOSIZE);
    imshow("output", src);
    waitKey();


    return EXIT_SUCCESS;
}