//开始之前，让我们自己开始再熟练熟练OpenNI 2的基本使用，主要包括以下几个步骤：
//1. 初始化OpenNI环境： openni::OpenNI::initialize();
//2. 声明并打开Device设备： openni::Device devAnyDevice; devAnyDevice.open(openni::ANY_DEVICE);
//3. 创建并打开深度数据流：openni::VideoStream streamDepth; streamDepth.create(devAnyDevice, openni::SENSOR_DEPTH); streamDepth.start();
//4. 读取数据流信息并保存在VideoFrameRef中：openni::VideoFrameRef frameDepth; streamDepth.readFrame(&frameDepth);
//5. 获取深度（或颜色等）数据，开始我们自己的开发之旅： const openni::DepthPixel * pDepth = (const openni::DepthPixel*)frameDepth.getData();
//6. 当结束使用数据时，首先关闭、销毁数据流：streamDepth.destroy();
//7. 接着关闭设备： devAnyDevice.close();
//8. 最后关闭OpenNI：  openni::OpenNI::shutdown();
//具体代码如下（环境配置在之前的博文中提及了，这里省去）

#include <iostream>
#include "OpenNI.h"

int main(int argc, char** argv)
{
    // 初始化OpenNI环境
    openni::OpenNI::initialize();

    // 声明并打开Device设备，我用的是Kinect。
    openni::Device devAnyDevice;
    devAnyDevice.open(openni::ANY_DEVICE);

    // 创建并打开深度数据流
    openni::VideoStream streamDepth;
    streamDepth.create(devAnyDevice, openni::SENSOR_DEPTH);
    streamDepth.start();

    // 同样的创建并打开彩色图像数据流
    openni::VideoStream streamColor;
    streamColor.create(devAnyDevice, openni::SENSOR_COLOR);
    streamColor.start();

    // 循环读取数据流信息并保存在VideoFrameRef中
    openni::VideoFrameRef frameDepth;
    openni::VideoFrameRef frameColor;
    for (int i = 0; i < 1000; ++i)
    {
        // 读取数据流
        streamDepth.readFrame(&frameDepth);
        streamColor.readFrame(&frameColor);

        // 获取data array
        const openni::DepthPixel* pDepth
            = (const openni::DepthPixel*)frameDepth.getData();
        const openni::RGB888Pixel* pColor
            = (const openni::RGB888Pixel*)frameColor.getData();

        // 显示深度信息和对应的彩色R、G、B数值
        int idx = frameDepth.getWidth() * (frameDepth.getHeight() + 1) / 2;
        std::cout << pDepth[idx] << "( "
            << (int)pColor[idx].r << ","
            << (int)pColor[idx].g << ","
            << (int)pColor[idx].b << ")"
            << std::endl;
    }

    // 关闭数据流
    streamDepth.destroy();
    streamColor.destroy();

    // 关闭设备
    devAnyDevice.close();

    // 最后关闭OpenNI
    openni::OpenNI::shutdown();

    return 0;
}
