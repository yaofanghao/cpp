# python 3.7
import numpy
import cv2
# import openni
from openni import openni2
import paddlex as pdx
from paddlex import transforms as T
import os

def show_depth_value(event, x, y, flags, param):
    global depth
    print(depth[y, x])

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
    # dev.set_image_registration_mode(
    #     openni2.IMAGE_REGISTRATION_DEPTH_TO_COLOR)
    # help(dev.set_image_registration_mode)

    # cv2.namedWindow('depth')


    cv2.namedWindow('mix',cv2.WINDOW_NORMAL)

    flag = 0
    model = pdx.load_model('best_model')

    while True:
        # Get depth
        depth_frame = depth_stream.read_frame()
        h, w = depth_frame.height, depth_frame.width
        depth = numpy.ctypeslib.as_array(
            depth_frame.get_buffer_as_uint16()).reshape(h, w)
        depth_uint8 = cv2.convertScaleAbs(depth, alpha=depth_scale_factor)
        depth_colored = cv2.applyColorMap(depth_uint8, cv2.COLORMAP_HSV)
        # Get color
        color_frame = color_stream.read_frame()
        color = numpy.ctypeslib.as_array(color_frame.get_buffer_as_uint8()).reshape(h, w, 3)
        color = cv2.cvtColor(color, cv2.COLOR_RGB2BGR)

        flag += 1

        # if flag%10==0:
        # fastscnn模型分割
        result = model.predict(color)

        # print(color)
        # print('-----------------')
        # print(result['label_map'])
        mask = result['label_map']
        mask2 = numpy.stack((mask,)*3, axis=-1)  # 单通道灰度转换为三通道
        mask3 = (mask2*255).astype(numpy.uint8)  # 转换为opencv可显示的格式

        # print(color.dtype) # uint8
        # print(mask2.dtype) # int32
        # print(mask3.dtype) # uint8

        # 画轮廓
        # contours, hierarchy = cv2.findContours(numpy.uint8(mask*255), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
        # draw_img = cv2.drawContours(color, contours, -1, (0, 0, 255), 5)
        #
        # for i in range(len(contours)):
        #     x, y, w, h = cv2.boundingRect(contours[i])
        #     cv2.putText(color,'hand',(x,y),cv2.FONT_HERSHEY_SIMPLEX,2, (0, 0, 255), 2)

        overlap = cv2.addWeighted(color,0.2,mask3,0.8,0,dtype=cv2.CV_8UC3)
        # cv2.imshow('predict',mask3)

        cv2.imshow('mix',overlap)

        # pdx.seg.visualize(color, result, weight=0.2, save_dir='output/', color=[255,255,255,0,0,0])

        # cv2.imshow('depth', depth_uint8)
        # cv2.imshow('depth colored', depth_colored)
        cv2.imshow('color', color)
        cv2.setMouseCallback('color', show_depth_value)

        k = cv2.waitKey(10) & 0xff
        if k == 27:
            break

    cv2.destroyAllWindows()
    depth_stream.stop()
    color_stream.stop()
    openni2.unload()