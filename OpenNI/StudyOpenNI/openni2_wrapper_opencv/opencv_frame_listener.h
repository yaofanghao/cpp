#ifndef OPENCV_FRAME_LISTENER_H_
#define OPENCV_FRAME_LISTENER_H_

#include "openni2_frame_listener.h"

namespace cv {
class Mat;
}

class OpenCVFrameListener : public OpenNI2FrameListener {
 public:
  OpenCVFrameListener();
  virtual ~OpenCVFrameListener();

  virtual void onNewCVFrame(const cv::Mat& cv_frame);

 private:
};


#endif
