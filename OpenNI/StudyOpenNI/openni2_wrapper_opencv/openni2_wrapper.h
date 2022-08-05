#ifndef OPENNI2_WRAPPER_H_
#define OPENNI2_WRAPPER_H_

#include <string>
#include "OpenNI.h"

#include "openni2_frame_listener.h"

using std::string;

class OpenNI2Wrapper {
 public:
  OpenNI2Wrapper();
  OpenNI2Wrapper(const string& device_id);

  virtual ~OpenNI2Wrapper();

  void SetFrameListener(OpenNI2FrameListener* frame_listner);

  void StartDepthStream();
  void StartDepthStream(int width, int height);

  void StopDepthStream();

 private:
  void InitDevice(const string& device_id);

  void CloseDevice();

  bool CreateDepthVideoStream();

  void DestroyDepthVideoStream();

  float GetDepthFocalLength(int frame_height) const;

  void SetImageRegistrationMode(bool enabled);

  void SetDepthResolution(int width, int height);

  openni::Device device_;
  openni::DeviceInfo device_info_;
  openni::VideoStream depth_video_stream_;

  OpenNI2FrameListener* frame_listner_;
};

#endif
