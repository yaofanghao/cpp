#include <assert.h>
#include <cmath>
#include <iostream>
//#include <unistd.h>

#include "openni2_wrapper.h"


OpenNI2Wrapper::OpenNI2Wrapper(const string& device_id)
    : frame_listner_(0) {
  InitDevice(device_id);
}

OpenNI2Wrapper::OpenNI2Wrapper()
    : frame_listner_(0) {
  InitDevice("");
}

OpenNI2Wrapper::~OpenNI2Wrapper() {
  StopDepthStream();
  DestroyDepthVideoStream();
  CloseDevice();

}

void OpenNI2Wrapper::SetFrameListener(OpenNI2FrameListener* frame_listner) {
  frame_listner_ = frame_listner;
}

void OpenNI2Wrapper::InitDevice(const string& device_id) {

  openni::Status rc = openni::OpenNI::initialize();
  if (rc != openni::STATUS_OK) {
    std::cerr << "Initialize failed: "
        << string(openni::OpenNI::getExtendedError()) << std::endl;
    return;
  }

  if (device_id.length() > 0) {
    rc = device_.open(device_id.c_str());
  } else {
    rc = device_.open(openni::ANY_DEVICE);
  }
  if (rc != openni::STATUS_OK) {
    std::cerr << "Initialize failed: "
        << string(openni::OpenNI::getExtendedError()) << std::endl;
    return;
  }
  device_info_ = device_.getDeviceInfo();

  assert(CreateDepthVideoStream());

  SetImageRegistrationMode(false);
}

void OpenNI2Wrapper::CloseDevice() {
  device_.close();
}

bool OpenNI2Wrapper::CreateDepthVideoStream() {
  if (device_.hasSensor(openni::SENSOR_DEPTH)) {
    const openni::Status rc = depth_video_stream_.create(device_, openni::SENSOR_DEPTH);
    if (rc != openni::STATUS_OK) {
      std::cerr << "Initialize failed: "
          << string(openni::OpenNI::getExtendedError()) << std::endl;
      return false;
    }
  } else {
    std::cerr << "Device does not have depth sensor: ";
    return false;
  }
  return true;
}

void OpenNI2Wrapper::DestroyDepthVideoStream() {
  depth_video_stream_.destroy();
}

float OpenNI2Wrapper::GetDepthFocalLength(int frame_height) const {
  return (float) frame_height
      / (2 * tan(depth_video_stream_.getVerticalFieldOfView() / 2));

}

void OpenNI2Wrapper::SetImageRegistrationMode(bool enabled) {
  if (device_.isImageRegistrationModeSupported(
      openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR)) {
    openni::Status rc;
    if (enabled) {
      rc = device_.setImageRegistrationMode(
          openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR);
    } else {
      rc = device_.setImageRegistrationMode(openni::IMAGE_REGISTRATION_OFF);
    }
    if (rc != openni::STATUS_OK) {
      std::cerr << "Enabling image registration mode failed: "
          << string(openni::OpenNI::getExtendedError()) << std::endl;
    }
  } else {
    std::cerr << "Image depth registration mode not supported";
  }
}

void OpenNI2Wrapper::StartDepthStream(int width, int height) {
  SetDepthResolution(width, height);
  StartDepthStream();
}

void OpenNI2Wrapper::StartDepthStream() {
  if (frame_listner_ != 0) {
    depth_video_stream_.setMirroringEnabled(false);
    depth_video_stream_.start();
    depth_video_stream_.addNewFrameListener(frame_listner_);
  } else {
    std::cerr << "Undefined frame listener";
  }
}

void OpenNI2Wrapper::StopDepthStream() {
  depth_video_stream_.removeNewFrameListener(frame_listner_);
  depth_video_stream_.stop();
}

void OpenNI2Wrapper::SetDepthResolution(int width, int height) {
  openni::VideoMode video_mode = depth_video_stream_.getVideoMode();
  video_mode.setResolution(width, height);
  const openni::Status rc = depth_video_stream_.setVideoMode(video_mode);
  if (rc != openni::STATUS_OK) {
    std::cerr << "Couldn't set IR video mode: "
        << string(openni::OpenNI::getExtendedError()) << std::endl;
  }
}

