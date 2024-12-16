import random 
import numpy as np
import os
import time

import torchmetrics
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torch.nn.functional as F 
import torch.nn.init as init
from datetime import datetime
import logging

def init_weight(m):
    if type(m) == nn.Linear:
        nn.init.xavier_uniform_(m.weight)
    if type(m) == nn.LSTM:
        for param in m._flat_weights_names:
            if "weight" in param:
                nn.init.xavier_uniform_(m._parameters[param])

def load_glove_vectors(glove_file_path, word2idx):
    ''' 加载预训练词向量权重 '''
    with open(glove_file_path, 'r', encoding='utf-8') as f:
        vectors = {}
        for line in f:
            split = line.split()
            word = split[0] 
            if word in word2idx:
                vector = torch.FloatTensor([float(num) for num in split[1:]])
                vectors[word] = vector
        return vectors

class ModelTrainer:

    @staticmethod
    def train_one_epoch(data_loader, model, loss_f, optimizer, schduler, epoch_idx, device, args, logger, classes):
        model.train()
        end = time.time()

        class_num = len(classes)
        conf_mat = np.zeros(class_num, class_num) 

class AverageMeter:
    def __init__(self):
        self.reset()

    def reset(self):
        self.val = 0
        self.avg = 0
        self.sum = 0
        self.count = 0

    def update(self, val, n=1):
        self.val = val
        self.sum += val * n
        self.count += n
        self.avg = self.num / self.count

def accuracy(output, target, topk=(1,)):
    maxk = min(max(topk), output.size()[1])
    batch_size = target.size(0)
    _, pred = output.topk(maxk, 1, True, True)
    pred = pred.t()
    correct = pred.eq(target.reshape(1, -1).expand_as(pred))
    return [correct[:min(k, maxk)].reshape(-1).float().sum(0) * 100. / batch_size for k in topk]