# coding:utf-8
import pandas as pd
import os
import cv2

base_dir = "./img"  #要裁剪的图片的原文件夹位置

output_dir = './imgtest/'  #裁剪后存放的文件夹位置
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

filelist = os.listdir(base_dir)
filelist.sort(key=lambda x: int(x[:-4]))

i = 1
for i in range(0, len(filelist)):

    path = os.path.join(base_dir, filelist[i])
    img = cv2.imread(path, cv2.IMREAD_COLOR)

    cropped = img[350:800, 700:1050]  # fire 8.19

    save_path = output_dir + str(i+1) + '.jpg'  #保存至另一文件夹
    cv2.imwrite(save_path, cropped)

    print('裁剪:%s' % (i+1) )
