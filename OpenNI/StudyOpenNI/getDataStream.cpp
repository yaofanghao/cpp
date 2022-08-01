//��ʼ֮ǰ���������Լ���ʼ����������OpenNI 2�Ļ���ʹ�ã���Ҫ�������¼������裺
//1. ��ʼ��OpenNI������ openni::OpenNI::initialize();
//2. ��������Device�豸�� openni::Device devAnyDevice; devAnyDevice.open(openni::ANY_DEVICE);
//3. �������������������openni::VideoStream streamDepth; streamDepth.create(devAnyDevice, openni::SENSOR_DEPTH); streamDepth.start();
//4. ��ȡ��������Ϣ��������VideoFrameRef�У�openni::VideoFrameRef frameDepth; streamDepth.readFrame(&frameDepth);
//5. ��ȡ��ȣ�����ɫ�ȣ����ݣ���ʼ�����Լ��Ŀ���֮�ã� const openni::DepthPixel * pDepth = (const openni::DepthPixel*)frameDepth.getData();
//6. ������ʹ������ʱ�����ȹرա�������������streamDepth.destroy();
//7. ���Źر��豸�� devAnyDevice.close();
//8. ���ر�OpenNI��  openni::OpenNI::shutdown();
//����������£�����������֮ǰ�Ĳ������ἰ�ˣ�����ʡȥ��

#include <iostream>
#include "OpenNI.h"

int main(int argc, char** argv)
{
    // ��ʼ��OpenNI����
    openni::OpenNI::initialize();

    // ��������Device�豸�����õ���Kinect��
    openni::Device devAnyDevice;
    devAnyDevice.open(openni::ANY_DEVICE);

    // �����������������
    openni::VideoStream streamDepth;
    streamDepth.create(devAnyDevice, openni::SENSOR_DEPTH);
    streamDepth.start();

    // ͬ���Ĵ������򿪲�ɫͼ��������
    openni::VideoStream streamColor;
    streamColor.create(devAnyDevice, openni::SENSOR_COLOR);
    streamColor.start();

    // ѭ����ȡ��������Ϣ��������VideoFrameRef��
    openni::VideoFrameRef frameDepth;
    openni::VideoFrameRef frameColor;
    for (int i = 0; i < 1000; ++i)
    {
        // ��ȡ������
        streamDepth.readFrame(&frameDepth);
        streamColor.readFrame(&frameColor);

        // ��ȡdata array
        const openni::DepthPixel* pDepth
            = (const openni::DepthPixel*)frameDepth.getData();
        const openni::RGB888Pixel* pColor
            = (const openni::RGB888Pixel*)frameColor.getData();

        // ��ʾ�����Ϣ�Ͷ�Ӧ�Ĳ�ɫR��G��B��ֵ
        int idx = frameDepth.getWidth() * (frameDepth.getHeight() + 1) / 2;
        std::cout << pDepth[idx] << "( "
            << (int)pColor[idx].r << ","
            << (int)pColor[idx].g << ","
            << (int)pColor[idx].b << ")"
            << std::endl;
    }

    // �ر�������
    streamDepth.destroy();
    streamColor.destroy();

    // �ر��豸
    devAnyDevice.close();

    // ���ر�OpenNI
    openni::OpenNI::shutdown();

    return 0;
}
