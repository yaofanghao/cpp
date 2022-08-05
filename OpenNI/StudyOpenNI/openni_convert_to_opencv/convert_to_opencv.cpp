#include "stdafx.h"
#include <iostream>
#include "OpenNI.h"

// ����OpenCVͷ�ļ�
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace openni;
using namespace cv;

int main(int argc, char** argv)
{
    // ��ʼ��OpenNI����
    OpenNI::initialize();

    // ��������Device�豸
    Device devAnyDevice;
    devAnyDevice.open(ANY_DEVICE);

    // �������������
    VideoStream streamDepth;
    streamDepth.create(devAnyDevice, SENSOR_DEPTH);

    // ������ɫͼ��������
    VideoStream streamColor;
    streamColor.create(devAnyDevice, SENSOR_COLOR);

    // �������ͼ����Ƶģʽ
    VideoMode mModeDepth;
    // �ֱ��ʴ�С
    mModeDepth.setResolution(640, 480);
    // ÿ��30֡
    mModeDepth.setFps(30);
    // ���ظ�ʽ
    mModeDepth.setPixelFormat(PIXEL_FORMAT_DEPTH_1_MM);

    streamDepth.setVideoMode(mModeDepth);

    // ͬ�������ò�ɫͼ����Ƶģʽ
    VideoMode mModeColor;
    mModeColor.setResolution(640, 480);
    mModeColor.setFps(30);
    mModeColor.setPixelFormat(PIXEL_FORMAT_RGB888);

    streamColor.setVideoMode(mModeColor);

    // ͼ����׼
    if (devAnyDevice.isImageRegistrationModeSupported(
        IMAGE_REGISTRATION_DEPTH_TO_COLOR))
    {
        devAnyDevice.setImageRegistrationMode(IMAGE_REGISTRATION_DEPTH_TO_COLOR);
    }

    // ����Ⱥ�ͼ��������
    streamDepth.start();
    streamColor.start();

    // ����OpenCVͼ�񴰿�
    namedWindow("Depth Image", WINDOW_AUTOSIZE);
    namedWindow("Color Image", WINDOW_AUTOSIZE);

    // ���������ֵ
    int iMaxDepth = streamDepth.getMaxPixelValue();

    // ѭ����ȡ��������Ϣ��������VideoFrameRef��
    VideoFrameRef  frameDepth;
    VideoFrameRef  frameColor;

    while (true)
    {
        // ��ȡ������
        streamDepth.readFrame(&frameDepth);
        streamColor.readFrame(&frameColor);


        // ���������ת����OpenCV��ʽ
        const cv::Mat mImageDepth(frameDepth.getHeight(), frameDepth.getWidth(), CV_16UC1, (void*)frameDepth.getData());
        // Ϊ�������ͼ����ʾ�ĸ�������һЩ����CV_16UC1 ==> CV_8U��ʽ
        cv::Mat mScaledDepth;
        mImageDepth.convertTo(mScaledDepth, CV_8U, 255.0 / iMaxDepth);
        // ��ʾ�����ͼ��
        cv::imshow("Depth Image", mScaledDepth);


        //// ͬ���Ľ���ɫͼ������ת����OpenCV��ʽ
        //const cv::Mat mImageRGB(frameColor.getHeight(), frameColor.getWidth(), CV_8UC3, (void*)frameColor.getData());
        //// ���Ƚ�RGB��ʽת��ΪBGR��ʽ
        //cv::Mat cImageBGR;
        //cv::cvtColor(mImageRGB, cImageBGR, COLOR_RGB2BGR);
        //// Ȼ����ʾ��ɫͼ��
        //cv::imshow("Color Image", cImageBGR);

        // ��ֹ��ݼ�
        if (cv::waitKey(10) == 'q')
            break;
    }

    // �ر�������
    streamDepth.destroy();
    //streamColor.destroy();

    // �ر��豸
    devAnyDevice.close();

    // ���ر�OpenNI
    openni::OpenNI::shutdown();

    return 0;
}
