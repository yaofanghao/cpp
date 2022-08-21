
from PIL import Image
from PIL import ImageEnhance
import numpy as np

import json
import os


def FZ(AnnotFilePath, SaveDataDir):
    img = np.asarray(Image.open(AnnotFilePath))  # 读取图像
    # img1 = np.flip(img, 0)  # 上下翻转
    img1 = np.fliplr(img)  # 左右翻转

    # enh_con = ImageEnhance.Contrast(img)
    # contrast = 1.4
    # img1 = enh_con.enhance(contrast)

    #保存
    _, AnnotFileName = os.path.split(AnnotFilePath)
    NewPath = os.path.join(SaveDataDir, AnnotFileName)
    Image.fromarray(img1).save(NewPath)
    print(1)


file='E:\\MyGithub\\Cpp\\OpenCV\\fireDetection\\cascade_data\\cascade3.0\\0、数据准备3.0-8.21数据\\positive'
alist = os.listdir(file)
for i in range(0, len(alist)):
    path = os.path.join(file, alist[i])
    AnnotFilePath = path
    SaveDataDir = 'E:\\MyGithub\\Cpp\OpenCV\\fireDetection\\cascade_data\\cascade3.0\\0、数据准备3.0-8.21数据\\positive1'
    FZ(AnnotFilePath, SaveDataDir)  # 使用for循环批量转化

