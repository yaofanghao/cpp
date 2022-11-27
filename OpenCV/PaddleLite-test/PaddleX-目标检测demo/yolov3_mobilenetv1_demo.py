# 参考自 https://aistudio.baidu.com/bd-gpu-01/user/1054847/4440808/notebooks/4440808.ipynb
# 设置使用0号GPU卡（如无GPU，执行此代码后仍然会使用CPU训练模型）
import matplotlib
# matplotlib.use('Agg')
import os
# os.environ['CUDA_VISIBLE_DEVICES'] = '0'
import paddlex as pdx

# # coding:utf-8
# from paddlex import transforms as T
#
# # 定义训练和验证时的transforms
# train_transforms = T.Compose([
#      T.BatchRandomResize(
#          target_sizes=[
#              320, 352, 384, 416, 448, 480, 512, 544, 576, 608, 640, 672, 704,
#              736, 768
#          ],
#          interp='RANDOM'), T.Normalize(
#              mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
# ])
#
# eval_transforms = T.Compose([
#     T.Resize(
#         target_size=640, interp='CUBIC'), T.Normalize(
#             mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
# ])
#
# # 定义训练和验证所用的数据集
# train_dataset = pdx.datasets.VOCDetection(
#     data_dir='dataset/dataset',
#     file_list='dataset/dataset/train_list.txt',
#     label_list='dataset/dataset/labels.txt',
#     transforms=train_transforms,
#     num_workers=0,
#     shuffle=True)
# eval_dataset = pdx.datasets.VOCDetection(
#     data_dir='dataset/dataset',
#     file_list='dataset/dataset/val_list.txt',
#     label_list='dataset/dataset/labels.txt',
#     transforms=eval_transforms,
#     num_workers=0,
#     shuffle=False)
#
# # 初始化模型，并进行训练
# # API说明: https://paddlex.readthedocs.io/zh_CN/develop/apis/models/detection.html#paddlex-det-yolov3
# num_classes = len(train_dataset.labels)
# model = pdx.det.YOLOv3(num_classes=num_classes, backbone='MobileNetV1')
# model.train(
#     num_epochs=270,
#     train_dataset=train_dataset,
#     train_batch_size=8,
#     eval_dataset=eval_dataset,
#     pretrain_weights='COCO',
#     learning_rate=0.001 / 4,
#     warmup_steps=1000,
#     warmup_start_lr=0.0,
#     lr_decay_epochs=[216, 243],
#     save_interval_epochs=3,
#     save_dir='output/yolov3_mobilenetv1_coco')

# 单张图片
# model = pdx.load_model('output/yolov3_mobilenetv1_coco/best_model')
# image_name = '177.jpg'
# result = model.predict(image_name)
# pdx.det.visualize(image_name, result, threshold=0.5, save_dir='./output')

# 批量预测图片
model = pdx.load_model('best_model')
image_path = 'JPEGImages'
for i in os.listdir(image_path):
    image_name = os.path.join(image_path,i)
    result = model.predict(image_name)
    pdx.det.visualize(image_name, result, threshold=0.5, save_dir='./output')


# # 显示图像
# %matplotlib inline
# import matplotlib.pyplot as plt
# import matplotlib.image as mpimg
# f1='177.jpg'
# f2="output/visualize_177.jpg"
# # f3="facade/JPEGImages/spatial_envelope_256x256_static_8outdoorcategories__street_urb206.jpg"
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