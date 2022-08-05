#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "opencv_frame_listener.h"

OpenCVFrameListener::OpenCVFrameListener() {
  cv::namedWindow( "Depth Video", cv::WINDOW_AUTOSIZE );
}

OpenCVFrameListener::~OpenCVFrameListener() {
}

void OpenCVFrameListener::onNewCVFrame(const cv::Mat& cv_frame) {
  cv::Mat frame_normalized;
  cv::normalize(cv_frame, frame_normalized, 0, 255, cv::NORM_MINMAX, CV_8UC1);

  cv::imshow( "Depth Video", frame_normalized );
  cv::waitKey(1);
}
