# python 3.7
import numpy
import cv2
from openni import openni2


def show_depth_value(event, x, y, flags, param):
    global depth
    print(depth[y, x])


video_save_path = "out.avi"
video_fps = 30

if __name__ == '__main__':
    openni2.initialize('E:\OpenNI\Redist')  # can also accept the path of the OpenNI redistribution
    dev = openni2.Device.open_any()

    depth_stream = dev.create_depth_stream()
    depth_stream.start()
    color_stream = dev.create_color_stream()
    color_stream.start()
    depth_scale_factor = 255.0 / depth_stream.get_max_pixel_value()
    print(depth_stream.get_max_pixel_value())

    ## Synchronize the streams
    dev.set_depth_color_sync_enabled(True)  # synchronize the streams

    ## rgb和depth图像对齐
    dev.set_image_registration_mode(
        openni2.IMAGE_REGISTRATION_DEPTH_TO_COLOR)

    cv2.namedWindow('depth')
    cv2.setMouseCallback('depth', show_depth_value)

    if video_save_path != "":
        fourcc = cv2.VideoWriter_fourcc('X', 'V', 'I', 'D')
        size = (320, 240)
        out = cv2.VideoWriter(video_save_path, fourcc, video_fps, size)

    while True:
        # Get depth
        depth_frame = depth_stream.read_frame()
        h, w = depth_frame.height, depth_frame.width  # 320,240
        depth = numpy.ctypeslib.as_array(
            depth_frame.get_buffer_as_uint16()).reshape(h, w)
        depth_uint8 = cv2.convertScaleAbs(depth, alpha=depth_scale_factor)
        depth_colored = cv2.applyColorMap(depth_uint8, cv2.COLORMAP_HSV)

        # Get color
        color_frame = color_stream.read_frame()

        color = numpy.ctypeslib.as_array(color_frame.get_buffer_as_uint8()).reshape(h, w, 3)
        color = cv2.cvtColor(color, cv2.COLOR_RGB2BGR)

        cv2.imshow('depth', depth_uint8)
        cv2.imshow('depth colored', depth_colored)
        cv2.imshow('color', color)

        out.write(color)

        k = cv2.waitKey(10) & 0xff
        if k == 27:
            break

    if video_save_path != "":
        print("Save processed video to the path :" + video_save_path)
        out.release()

    cv2.destroyAllWindows()
    depth_stream.stop()
    color_stream.stop()
    openni2.unload()