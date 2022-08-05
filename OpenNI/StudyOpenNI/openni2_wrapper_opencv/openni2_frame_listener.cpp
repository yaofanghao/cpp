#include <iostream>
#include <opencv2/opencv.hpp>
#include "openni2_frame_listener.h"

OpenNI2FrameListener::OpenNI2FrameListener() {
}

OpenNI2FrameListener::~OpenNI2FrameListener() {
}

void OpenNI2FrameListener::onNewFrame(openni::VideoStream& stream) {
  stream.readFrame(&m_frame);

  if (m_frame.isValid()) {
    const openni::VideoMode& video_mode = m_frame.getVideoMode();
    const openni::PixelFormat format = video_mode.getPixelFormat();
    if (format == openni::PIXEL_FORMAT_DEPTH_1_MM) {
      std::size_t data_size = m_frame.getDataSize();
      int width = m_frame.getWidth();
      int height = m_frame.getHeight();
      cv::Mat cv_frame(cv::Size(width, height), CV_16U);
      memcpy(cv_frame.data, m_frame.getData(), data_size);
      onNewCVFrame(cv_frame);
    } else {
      std::cerr << "Invalid image encoding" << std::endl;
    }

  }
}
