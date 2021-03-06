# coding:utf-8
import pandas as pd
import os
import cv2

base_dir = "./imgday"  #要裁剪的图片的原文件夹位置

output_dir = './positive/'  #裁剪后存放的文件夹位置
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

filelist = os.listdir(base_dir)

i = 1
for i in range(0, len(filelist)):

    path = os.path.join(base_dir, filelist[i])
    img = cv2.imread(path, cv2.IMREAD_COLOR)

    cropped = img[260:400, 600:750] #day
    # cropped = img[190:350, 300:500] #night

    save_path = output_dir + str(i+1) + '.jpg'  #保存至另一文件夹
    cv2.imwrite(save_path, cropped)

    print('裁剪:%s' % (i+1) )
