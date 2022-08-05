import caffe
from caffe import layers as L, params as P
from caffe.coord_map import crop
# this file determine the basic net structure
def conv_relu(bottom, nout, ks=3, stride=1, pad=1):
    conv = L.Convolution(bottom, kernel_size=ks, stride=stride,
        num_output=nout, pad=pad,
        param=[dict(lr_mult=1, decay_mult=1), dict(lr_mult=2, decay_mult=0)])
    return conv, L.ReLU(conv, in_place=True)

def max_pool(bottom, ks=4, stride=4):
    return L.Pooling(bottom, pool=P.Pooling.MAX, kernel_size=ks, stride=stride)

def fcn(split):
    n = caffe.NetSpec()
    if(split == 'train'):
        n.depth, n.joint = L.HDF5Data(batch_size=64, source='train.txt', ntop=2)
    else:
        n.depth, n.joint = L.HDF5Data(batch_size=64, source='test.txt', ntop=2)
    # the base net
    n.conv1, n.relu1 = conv_relu(n.depth, 8, 5)
    n.pool1 = max_pool(n.relu1)

    n.conv2, n.relu2 = conv_relu(n.pool1, 8, 5)
    n.pool2 = max_pool(n.relu2)

    n.conv3, n.relu3 = conv_relu(n.pool2, 8, 3)

    # fully connected
    n.ip1 = L.InnerProduct(n.relu3, num_output=1024,
        weight_filler=dict(type='xavier'))
    n.relu4 = L.ReLU(n.ip1, in_place=True)
    n.drop4 = L.Dropout(n.relu4, dropout_ratio=0.3, in_place=True)

    n.ip2 = L.InnerProduct(n.drop4, num_output=1024,
        weight_filler=dict(type='xavier'))
    n.relu5 = L.ReLU(n.ip2, in_place=True)
    n.drop5 = L.Dropout(n.relu5, dropout_ratio=0.3, in_place=True)

    n.Bottleneck = L.InnerProduct(n.drop5, num_output=30,
        weight_filler=dict(type='xavier'))

    n.DeepHandModelxyz = L.DeepHandModel(n.Bottleneck)

    n.DeepHandModelxyzloss = L.EuclideanLoss(n.DeepHandModelxyz, n.joint)

    return n.to_proto()

def make_net():
    with open('train.prototxt', 'w') as f:
        f.write(str(fcn('train')))

    with open('val.prototxt', 'w') as f:
        f.write(str(fcn('val')))

if __name__ == '__main__':
    make_net()
