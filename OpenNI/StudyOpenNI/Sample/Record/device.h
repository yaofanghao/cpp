#ifndef __DEVICE__
#define __DEVICE__

#include <OpenNI.h>
#include <opencv2/opencv.hpp>

#define RECORD

class Device
{
private:
    // Device
    openni::Device device;
    openni::VideoStream color_stream;
    openni::VideoStream depth_stream;

    // Recorder
    #ifdef RECORD
    openni::Recorder recorder;
    #endif
    std::string file = "file.oni";

    // Color Buffer
    openni::VideoFrameRef color_frame;
    cv::Mat color_mat;
    uint32_t color_width = 640;
    uint32_t color_height = 480;
    uint32_t color_fps = 30;

    // Depth Buffer
    openni::VideoFrameRef depth_frame;
    cv::Mat depth_mat;
    uint32_t depth_width = 640;
    uint32_t depth_height = 480;
    uint32_t depth_fps = 30;

public:
    // Constructor
    Device();

    // Destructor
    ~Device();

    // Processing
    void run();

private:
    // Initialize
    void initialize();

    // Initialize Device
    inline void initializeDevice();

    // Initialize Color
    inline void initializeColor();

    // Initialize Depth
    inline void initializeDepth();

    // Initialize Recorder
    inline void initializeRecorder();

    // Finalize
    void finalize();

    // Update Data
    void update();

    // Update Color
    inline void updateColor();

    // Update Depth
    inline void updateDepth();

    // Draw Data
    void draw();

    // Draw Color
    inline void drawColor();

    // Draw Depth
    inline void drawDepth();

    // Show Data
    void show();

    // Show Color
    inline void showColor();

    // Show Depth
    inline void showDepth();
};

#endif // __DEVICE__