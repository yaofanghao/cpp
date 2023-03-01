
# coding:utf-8
import pandas as pd
import os
import cv2

base_dir = "./deng"  #要裁剪的图片的原文件夹位置

output_dir = './deng_cut/'  #裁剪后存放的文件夹位置
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

filelist = os.listdir(base_dir)

i = 1
for i in range(0, len(filelist)):

    path = os.path.join(base_dir, filelist[i])
    img = cv2.imread(path, cv2.IMREAD_COLOR)

    cv2.rectangle(img, (300, 450), (1200, 700), (0, 0, 0), thickness=-1)

    save_path = output_dir + str(i+1) + '.jpg'  #保存至另一文件夹

    cv2.imwrite(save_path, img)

    print('裁剪:%s' % (i+1) )



