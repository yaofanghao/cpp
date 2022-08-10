# https://google.github.io/mediapipe/solutions/objectron
# https://www.youtube.com/watch?v=f-Ibri14KMY&t=226s

import numpy
import cv2
from openni import openni2
import mediapipe as mp
import time

use_mediapipe = 1

if __name__ == '__main__':
    openni2.initialize('E:\OpenNI\Redist')  # can also accept the path of the OpenNI redistribution
    dev = openni2.Device.open_any()
    depth_stream = dev.create_depth_stream()
    depth_stream.start()
    color_stream = dev.create_color_stream()
    color_stream.start()
    depth_scale_factor = 255.0 / depth_stream.get_max_pixel_value()
    print(depth_stream.get_max_pixel_value())
    # cv2.namedWindow('depth')

    while True:
        # Get depth
        depth_frame = depth_stream.read_frame()
        h, w = depth_frame.height, depth_frame.width
        depth = numpy.ctypeslib.as_array(depth_frame.get_buffer_as_uint16()).reshape(h, w)
        # depth_uint8 = cv2.convertScaleAbs(depth, alpha=depth_scale_factor)
        # depth_colored = cv2.applyColorMap(depth_uint8, cv2.COLORMAP_HSV)

        # Get color
        color_frame = color_stream.read_frame()
        color = numpy.ctypeslib.as_array(color_frame.get_buffer_as_uint8()).reshape(h, w, 3)
        color = cv2.cvtColor(color, cv2.COLOR_RGB2BGR)

        # 利用color图进行mediapipe objectron测试
        mp_objectron = mp.solutions.objectron
        mp_drawing = mp.solutions.drawing_utils

        # model_name: currently support {'Shoe', 'Chair', 'Cup', 'Camera'}.
        with mp_objectron.Objectron(static_image_mode=False,
                                    max_num_objects=2,
                                    min_detection_confidence=0.5,
                                    min_tracking_confidence=0.8,
                                    model_name='Cup') as objectron:
                # while use_mediapipe:
            start = time.time()
            # image = cv2.cvtColor(color, cv2.COLOR_BGR2RGB)
            image = color

            image.flags.writeable = False
            results = objectron.process(image)

            image.flags.writeable = True
            image = cv2.cvtColor(color, cv2.COLOR_RGB2BGR)

            if results.detected_objects:
                for detected_objects in results.detected_objects:
                    mp_drawing.draw_landmarks(image,
                                              detected_objects.landmarks_2d,
                                              mp_objectron.BOX_CONNECTIONS)
                    mp_drawing.draw_axis(image,
                                         detected_objects.rotation,
                                         detected_objects.translation)
                    print("find objects")

            end = time.time()
            totalTime = end - start
            fps = 1 / totalTime

            cv2.putText(image,f'FPS:{int(fps)}',(20,70),cv2.FONT_HERSHEY_SIMPLEX,
                        1,(0,255,0),1)
            cv2.imshow('Mediapipe Objectron',image)

        # Display
        # cv2.imshow('depth', depth_uint8)
        # cv2.imshow('depth colored', depth_colored)
        # cv2.imshow('color', color)

            k = cv2.waitKey(10) & 0xff
            if k == 27:
                break

    depth_stream.stop()
    openni2.unload()



