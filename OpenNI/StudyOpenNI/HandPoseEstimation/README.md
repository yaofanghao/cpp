<<<<<<< HEAD
# Model-based Deep Hand Pose Estimation
This repository is the released code of our IJCAI 2016 [paper](http://xingyizhou.xyz/zhou2016model.pdf) for estimating hand pose from depth image.

Contact: zhouxy13@fudan.edu.cn

## Requirements
- Caffe
- Python with opencv

## Installation
- Download [caffe](http://caffe.berkeleyvision.org/) 
- Copy ./libs/include to caffe_root/include and ./libs/src to caffe_root/src
- Compile caffe
- Copy path.config.example to path.config and set the pycaffe path

## Test
- Run demo.py in ./testing
- Our prediction on NYU dataset [here](http://xingyizhou.xyz/IJCAI16_NYU.txt)
- Our prediction on ICVL dataset [here](http://xingyizhou.xyz/IJCAI16_ICVL.txt)

## Train
- download [NYU](http://cims.nyu.edu/~tompson/NYU_Hand_Pose_Dataset.htm#download) dataset
- set NYU_path in path.config
- Run GetH5DataNYU.py in ./training
- Train with solver.prototxt

## Citation

Please cite DeepModel in your publication if it helps your research:

    @inproceedings{zhou2016model,
        author = {Xingyi Zhou and Qingfu Wan and Wei Zhang and Xiangyang Xue and Yichen Wei},
        booktitle = {IJCAI},
        title = {Model-based Deep Hand Pose Estimation},
        year = {2016}
    }
=======
# HandPoseEstimation
>>>>>>> 197139b57d1d052b2b37bb9c4e27d37bfc3a24e5
