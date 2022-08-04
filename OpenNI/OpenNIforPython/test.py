from openni import openni2
import numpy as np
import cv2
import sys
import time

openni2.initialize('E:\OpenNI\Redist')  # can also accept the path of the OpenNI redistribution

dev = openni2.Device.open_any()
print(dev.get_device_info())

depth_stream = dev.create_depth_stream()
color_stream = dev.create_color_stream()
depth_stream.start()
color_stream.start()

while True:
    # 显示深度图
    frame = depth_stream.read_frame()
    dframe_data = np.array(frame.get_buffer_as_triplet()).reshape([240, 320, 2])
    dpt1 = np.asarray(dframe_data[:, :, 0], dtype='float32')
    dpt2 = np.asarray(dframe_data[:, :, 1], dtype='float32')
    dpt2 *= 255
    dpt = dpt1 + dpt2
    cv2.imshow('dpt', dpt)

    # 显示RGB图像
    cframe = color_stream.read_frame()
    cframe_data = np.array(cframe.get_buffer_as_triplet()).reshape([240, 320, 3])
    R = cframe_data[:, :, 0]
    G = cframe_data[:, :, 1]
    B = cframe_data[:, :, 2]
    cframe_data = np.transpose(np.array([B, G, R]), [1, 2, 0])
    # print(cframe_data.shape)
    cv2.imshow('color', cframe_data)

    i = 0
    # while(1):
    #    ret,frame = cframe_data.read()
    if cv2.waitKey(1) == ord('s'):
        cv2.imwrite('./%d.jpg' % i, cframe_data)  # %d 十进制数
        i += 1
    # waitKey()函数在一个给定的时间内(单位ms)等待用户按键触发;如果用户没有按下 键,则接续等待(循环)

    # 按下q键退出循环

# 关闭设备
depth_stream.stop()
color_stream.stop()
dev.close()