#ifndef OPENNI2_FRAME_LISTENER_H_
#define OPENNI2_FRAME_LISTENER_H_

#include "OpenNI.h"

namespace cv {
class Mat;
}

class OpenNI2FrameListener : public openni::VideoStream::NewFrameListener {
 public:
  OpenNI2FrameListener();
  virtual ~OpenNI2FrameListener();

  void onNewFrame(openni::VideoStream& stream);

  virtual void onNewCVFrame(const cv::Mat& cv_frame) = 0;

 private:
  openni::VideoFrameRef m_frame;
};


#endif
