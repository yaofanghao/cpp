import cv2
import numpy as np
import os
img_path = "deng1.png"

if __name__ == '__main__':

    img = cv2.imread(img_path)

    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(img_gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

    _, contours, hierarchy = cv2.findContours(
        thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    draw_img = cv2.drawContours(img, contours, -1, (0,0,255),5)
    cv2.imshow("result", draw_img)

    # 轮廓面积 圆形度 长度 特征
    img_area = img.shape[0] * img.shape[1]
    contoursImg = []
    cntLen = []
    num = 0
    print("总面积：",img_area)
    for i in range(len(contours)):
        temp = np.zeros(img.shape, np.uint8)
        contoursImg.append(temp)
        cntLen.append(cv2.arcLength(contours[i],True)) # 统计各轮廓长度
        roundIndex = 4 * 3.1415926 * cv2.contourArea(contours[i]) / ( cntLen[i] ** 2 + 0.00001)  # 圆形度 防止ZeroDivisionError
        roundIndex = round(roundIndex,3)
        print(str(i) + " 长度" + str(cntLen[i]) + "面积" + str(cv2.contourArea(contours[i])) + " 圆形度为：" + str(roundIndex))

    cv2.waitKey()
    cv2.destroyAllWindows()

