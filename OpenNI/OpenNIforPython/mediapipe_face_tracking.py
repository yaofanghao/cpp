# https://google.github.io/mediapipe/
# https://github.com/Fafa-DL/Opencv-project/tree/main/CVZone/21%20Face%20Detection

import numpy
import cv2
from openni import openni2
import mediapipe as mp
import time

mpFaceDetection = mp.solutions.face_detection
mpDraw = mp.solutions.drawing_utils
faceDetection = mpFaceDetection.FaceDetection(0.75)

pTime = 0
cTime = 0

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

        imgRGB = cv2.cvtColor(color, cv2.COLOR_BGR2RGB)
        results = faceDetection.process(imgRGB)
        # print(results)

        if results.detections:
            for id, detection in enumerate(results.detections):
                # mpDraw.draw_detection(img, detection)
                # print(id, detection)
                # print(detection.score)
                # print(detection.location_data.relative_bounding_box)
                bboxC = detection.location_data.relative_bounding_box
                ih, iw, ic = color.shape
                bbox = int(bboxC.xmin * iw), int(bboxC.ymin * ih), \
                       int(bboxC.width * iw), int(bboxC.height * ih)
                cv2.rectangle(color, bbox, (255, 0, 255), 2)
                cv2.putText(color, f'{int(detection.score[0] * 100)}%',
                            (bbox[0], bbox[1] - 20), cv2.FONT_HERSHEY_PLAIN,
                            2, (255, 0, 255), 2)

                center_x = int(bboxC.xmin * iw)+int(bboxC.width * iw)/2
                center_y = int(bboxC.ymin * ih)+int(bboxC.height * ih)/2
                cv2.circle(color,(int(center_x),int(center_y)),5,(0,0,255),5)



        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime
        # cv2.putText(color, f'FPS: {int(fps)}', (20, 70), cv2.FONT_HERSHEY_PLAIN,
        #             3, (0, 255, 0), 2)
        cv2.imshow("Image", color)

        k = cv2.waitKey(10) & 0xff
        if k == 27:
            break

    depth_stream.stop()
    openni2.unload()



