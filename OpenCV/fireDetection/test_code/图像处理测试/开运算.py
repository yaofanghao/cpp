import cv2
import numpy as np

img_path='2378-2.png'
kernal_size=11

kernal = np.ones((kernal_size,kernal_size), np.uint8)

def imgopen(mask, kernal_size):
    kernal2 = np.ones((kernal_size, kernal_size), np.uint8)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernal2)
    return mask

img = cv2.imread(img_path)
di =  cv2.dilate(img, kernal)
er = cv2.erode(img, kernal)

mask = imgopen(img, kernal_size)

mask1 =  cv2.erode(di,kernal); #闭运算

cv2.namedWindow("origin", cv2.WINDOW_NORMAL)
cv2.namedWindow("dilate", cv2.WINDOW_NORMAL)
cv2.namedWindow("erode", cv2.WINDOW_NORMAL)
cv2.namedWindow("open", cv2.WINDOW_NORMAL)
cv2.namedWindow("close", cv2.WINDOW_NORMAL)
cv2.imshow("origin",img)
cv2.imshow("dilate",di)
cv2.imshow("erode",er)
cv2.imshow("open",mask)
cv2.imshow("close",mask1)

cv2.imwrite('test2-pengzhang.jpg', di)
cv2.imwrite('test2-fushi.jpg', er)
cv2.imwrite('test2-open.jpg', mask)
cv2.imwrite('test2-close.jpg', mask1)


cv2.waitKey(0)