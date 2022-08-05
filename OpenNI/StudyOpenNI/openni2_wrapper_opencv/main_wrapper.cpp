#include "openni2_wrapper.h"
#include "opencv_frame_listener.h"

int main(int argc, char **argv){

  OpenNI2Wrapper openni_wrapper;
  OpenCVFrameListener frame_listener;

  openni_wrapper.SetFrameListener(&frame_listener);

  openni_wrapper.StartDepthStream(640, 480);

  while (true) {
    Sleep(100);
  }

  openni_wrapper.StopDepthStream();
  return 0;
}
