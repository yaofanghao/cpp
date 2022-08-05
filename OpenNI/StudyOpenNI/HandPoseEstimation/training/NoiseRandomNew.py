import numpy as np
import random
from skimage import draw,data
import h5py
import cv2
import scipy.io as sio
import sys
import os
import math
import matplotlib.pyplot as plt
paths = {}
with open('../path.config', 'r') as f:
  for line in f:
    name, path = line.split(': ')
    print name, path
    paths[name] = path

# the data path for train and test img
dataset_path = '/home/gtayx/handPose/NYUdata'
# the total joints are 36
J = 14
img_size = 128
joint_id = np.array([0, 3, 6, 9, 12, 15, 18, 21, 24, 25, 27, 30, 31, 32])
fx = 588.03  #640/1.08836710
fy = 587.07  #480/0.8176
fu = 320.
fv = 240.
##############################################################################
# input the image and the position of palm_5(uvd)
def CropImage(image, com):
  # u v d info of palm
  u, v, d = com
  d = d + np.random.choice(np.arange(-30,30))
  urand = np.random.choice(np.arange(-30,30))
  vrand = np.random.choice(np.arange(-30,30))
  u = u + urand
  v = v + vrand
  # z is equal to d
  zstart = d - cube_size_d / 2.
  zend = d + cube_size_d / 2.
  # transform xyz domain to uvz domain
  xstart = int(math.floor((u * d / fx - cube_size / 2.) / d * fx))
  xend = int(math.floor((u * d / fx + cube_size / 2.) / d * fx))
  ystart = int(math.floor((v * d / fy - cube_size / 2.) / d * fy))
  yend = int(math.floor((v * d / fy + cube_size / 2.) / d * fy))
  # select the cropped domain, if box is beyond the boundary just pad it
  cropped = depth[max(ystart, 0):min(yend, depth.shape[0]), max(xstart, 0):min(xend, depth.shape[1])].copy()
  cropped = np.pad(cropped, ((abs(ystart)-max(ystart, 0), abs(yend)-min(yend, depth.shape[0])),
                                (abs(xstart)-max(xstart, 0), abs(xend)-min(xend, depth.shape[1]))), mode='constant', constant_values=0)
  # for the depth beyond box just use the value on the box
  msk1 = np.bitwise_and(cropped < zstart, cropped != 0)
  msk2 = np.bitwise_and(cropped > zend, cropped != 0)
  msk3 = np.bitwise_and(cropped < zstart, cropped == 0)
  cropped[msk1] = zstart
  cropped[msk2] = zend
  # set the 0 to zend
  cropped[msk3] = zend
  # dsize is 128*128
  dsize = (img_size, img_size)
  wb = (xend - xstart)
  hb = (yend - ystart)
  # transform 150*150 to 128*128
  if wb > hb:
    sz = (dsize[0], hb * dsize[0] / wb)
  else:
    sz = (wb * dsize[1] / hb, dsize[1])
  rz = cv2.resize(cropped, sz)
  ret = np.ones(dsize, np.float32) * zend
  xstart = int(math.floor(dsize[0] / 2 - rz.shape[1] / 2))
  xend = int(xstart + rz.shape[1])
  ystart = int(math.floor(dsize[1] / 2 - rz.shape[0] / 2))
  yend = int(ystart + rz.shape[0])
  ret[ystart:yend, xstart:xend] = rz

  randChoice = (int)(10*random.random())
  if(randChoice%2 == 0):
    rand = int(100*random.random()) + 40
    noise_x_start = wb / 2 - urand + np.random.choice(np.arange(-50,50))- rand/2
    noise_y_start = hb / 2 - vrand + np.random.choice(np.arange(-120,60)) - rand/2
    noise_x_end = noise_x_start+ rand
    noise_y_end = noise_y_start+ rand
    cropped[noise_y_start:noise_y_end, noise_x_start:noise_x_end] = int(zend)
  else:
    noise_x_start = wb / 2 - urand + np.random.choice(np.arange(-50,50))
    noise_y_start = hb / 2 - vrand + np.random.choice(np.arange(-120,60))
    rr, cc = draw.ellipse(noise_y_start, noise_x_start, np.random.choice(np.arange(20,50)), np.random.choice(np.arange(20,50)))
    draw.set_color(cropped, [rr, cc], int(zend))
  # transform 150*150 to 128*128
  if wb > hb:
    sz = (dsize[0], hb * dsize[0] / wb)
  else:
    sz = (wb * dsize[1] / hb, dsize[1])
  rz = cv2.resize(cropped, sz)
  ret = np.ones(dsize, np.float32) * zend
  xstart = int(math.floor(dsize[0] / 2 - rz.shape[1] / 2))
  xend = int(xstart + rz.shape[1])
  ystart = int(math.floor(dsize[1] / 2 - rz.shape[0] / 2))
  yend = int(ystart + rz.shape[0])
  ret[ystart:yend, xstart:xend] = rz
  return ret
##############################################################################
for data_type in ['test', 'train']:
  # data_type = 'test'
  trainCount = 0
  idComb = [[0,20000],[20000,40000],[40000,60000],[60000,72000]]
  # select the cube size of the hand
  cube_size = 450
  cube_size_d = 300
  for trainCount in xrange(1,5):
    if data_type == 'test' and trainCount > 1:
      break
    if data_type == 'train':
      id_start = idComb[trainCount-1][0]
      id_end = idComb[trainCount-1][1]
    else:
      id_start = 0
      id_end = 8000

    if data_type == 'train':
      data_path = dataset_path + '/train/train'
      label_path = dataset_path + '/train/joint_data.mat'
    else:
      data_path = dataset_path + '/test/'
      label_path = dataset_path + '/test/joint_data.mat'

    labels = sio.loadmat(label_path)
    # save the joint info to joint_uvd and joint_xyz
    joint_uvd = labels['joint_uvd'][0]
    joint_xyz = labels['joint_xyz'][0]

    cnt = 0
    depth_h5, joint_h5, com_h5, inds_h5 = [], [], [], []
    for id in range(id_start, id_end):
      img_path = '{}/depth_1_{:07d}.png'.format(data_path, id + 1)
      print 'depth_1_{:07d}.png'.format(id + 1)
      # check whether path exist
      if not os.path.exists(img_path):
        print '{} Not Exists!'.format(img_path)
        continue
      img = cv2.imread(img_path)
      # get depth in each pixel
      depth = np.asarray(img[:, :, 0] + img[:, :, 1] * 256)
      # put the depth image and the palm info into function and crop it
      depth = CropImage(depth, joint_uvd[id, 35])  # + np.random.choice(np.arange(-10,10))

      com3D = joint_xyz[id, 35]
      # only our interested points we need to transform
      joint = joint_xyz[id][joint_id] - com3D
      # print joint.shape
      depth = ((depth - com3D[2]) / (cube_size_d / 2)).reshape(img_size, img_size)
      depth = np.asarray(depth[np.newaxis,...])

      # normalize the joint position
      joint = np.clip(joint / (cube_size / 2), -1, 1)
      joint = joint.reshape(3 * J)

      joint = np.asarray(joint[np.newaxis, np.newaxis, ...])
      # joint = np.asarray(joint)

      # print joint.shape
      depth_h5.append(depth.copy())
      # print np.asarray(depth_h5).shape

      # xyz save in the one file so reshape 3*J
      joint_h5.append(joint.copy())
      com_h5.append(com3D.copy())
      inds_h5.append(id)
      cnt += 1

      if id > id_end-2:
        #if test no random, else random dataset
        rng = np.arange(cnt) if data_type == 'test' else np.random.choice(np.arange(cnt), cnt, replace = False)
        if data_type == 'test':
          dset = h5py.File(dataset_path + '/PalmRandomWithNoise/{}_normal.h5'.format(data_type), 'w')
        elif data_type == 'train' and id_start == 0:
          dset = h5py.File(dataset_path + '/PalmRandomWithNoise/{}_normal_1.h5'.format(data_type), 'w')
        elif data_type == 'train' and id_start == 20000:
          dset = h5py.File(dataset_path + '/PalmRandomWithNoise/{}_normal_2.h5'.format(data_type), 'w')
        elif data_type == 'train' and id_start == 40000:
          dset = h5py.File(dataset_path + '/PalmRandomWithNoise/{}_normal_3.h5'.format(data_type), 'w')
        elif data_type == 'train' and id_start == 60000:
          dset = h5py.File(dataset_path + '/PalmRandomWithNoise/{}_normal_4.h5'.format(data_type), 'w')
        dset['depth'] = np.asarray(depth_h5)[rng]
        dset['joint'] = np.asarray(joint_h5)[rng]
        dset.close()
        depth_h5, joint_h5, com_h5, inds_h5 = [], [], [], []
        cnt = 0
        break


