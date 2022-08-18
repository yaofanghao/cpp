import paddlex as pdx
from paddlex import transforms as T
import os

# # 下载和解压视盘分割数据集
# # optic_dataset = 'https://bj.bcebos.com/paddlex/datasets/optic_disc_seg.tar.gz'
# # pdx.utils.download_and_decompress(optic_dataset, path='./')
#
# # 定义训练和验证时的transforms
# # API说明：https://github.com/PaddlePaddle/PaddleX/blob/develop/docs/apis/transforms/transforms.md
# train_transforms = T.Compose([
#     T.Resize(target_size=512),
#     T.RandomHorizontalFlip(),
#     T.Normalize(
#         mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5]),
# ])
#
# eval_transforms = T.Compose([
#     T.Resize(target_size=512),
#     T.Normalize(
#         mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5]),
# ])
#
# # 定义训练和验证所用的数据集
# # API说明：https://github.com/PaddlePaddle/PaddleX/blob/develop/docs/apis/datasets.md
# train_dataset = pdx.datasets.SegDataset(
#     data_dir='MyHandData/816/VOChand',
#     file_list='MyHandData/816/VOChand/train_list.txt',
#     label_list='MyHandData/816/VOChand/labels.txt',
#     transforms=train_transforms,
#     shuffle=True)
#
# eval_dataset = pdx.datasets.SegDataset(
#     data_dir='MyHandData/816/VOChand',
#     file_list='MyHandData/816/VOChand/val_list.txt',
#     label_list='MyHandData/816/VOChand/labels.txt',
#     transforms=eval_transforms,
#     shuffle=False)
#
# # 初始化模型，并进行训练
# # 可使用VisualDL查看训练指标，参考https://paddlex.readthedocs.io/zh_CN/develop/train/visualdl.html
# num_classes = len(train_dataset.labels)
# # API说明：https://paddlex.readthedocs.io/zh_CN/develop/apis/models/semantic_segmentation.html#paddlex-seg-fastscnn
# model = pdx.seg.FastSCNN(num_classes=num_classes)
#
# # API说明：https://paddlex.readthedocs.io/zh_CN/develop/apis/models/semantic_segmentation.html#train
# # 各参数介绍与调整说明：https://paddlex.readthedocs.io/zh_CN/develop/appendix/parameters.html
# model.train(
#     num_epochs=20,
#     train_dataset=train_dataset,
#     train_batch_size=8,
#     eval_dataset=eval_dataset,
#     learning_rate=0.01,
#     save_dir='output/fastscnn',
#     use_vdl=True)

#模型预测
# 单张图片
# model = pdx.load_model('best_model')
# image_name = 'images/118.jpg'
# result = model.predict(image_name)
# pdx.seg.visualize(image_name, result, weight=0.4, save_dir='output/')

# 批量预测图片
model = pdx.load_model('best_model')
image_path = 'JPEGImages'
for i in os.listdir(image_path):
    image_name = os.path.join(image_path,i)
    result = model.predict(image_name)
    pdx.seg.visualize(image_name, result, weight=0.2, save_dir='output/')

# # 显示图像
# # %matplotlib inline
# import matplotlib.pyplot as plt
# import matplotlib.image as mpimg
# f1='images/118.jpg'
# f2="output/visualize_118.jpg"
# # f3="facade/images/spatial_envelope_256x256_static_8outdoorcategories__street_urb206.jpg"
# # f4="output/fastscnn/visualize_spatial_envelope_256x256_static_8outdoorcategories__street_urb206.jpg"
# img1=mpimg.imread(f1)
# img2=mpimg.imread(f2)
# # img3=mpimg.imread(f3)
# # img4=mpimg.imread(f4)
# plt.subplot(211)
# plt.imshow(img1)
# plt.subplot(212)
# plt.imshow(img2)
# # plt.subplot(223)
# # plt.imshow(img3)
# # plt.subplot(224)
# # plt.imshow(img4)
# plt.show()