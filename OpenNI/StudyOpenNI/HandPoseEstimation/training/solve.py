import caffe
import numpy as np
import os
# run this file is runing the training
weights = "base.caffemodel"
caffe.set_mode_gpu()

solver = caffe.SGDSolver('solver.prototxt')
solver.net.copy_from(weights)
solver.solve()
