import os
import sys
import time 
import torchvision
import torchvision.transforms as transforms
import torch
import torch.nn as nn
import matplotlib
import matplotlib.pyplot as plt
from PIL import Image
import platform
from torch.utils.data import DataLoader
import torch.nn.functional as F


BASE_DIR = os.path.dirname(__file__)
PRJ_DIR = os.path.abspath(os.path.join(BASE_DIR, ".."))
sys.path.append(PRJ_DIR)


class LSTMTextClassifier(nn.Module):
    def __init__(self, vocab_size, embed_size, num_hiddens, num_layers, **kwargs):
        super(LSTMTextClassifier, self).__init__(**kwargs)

        self.embedding = nn.Embedding(vocab_size, embed_size)
        self.encoder = nn.LSTM(embed_size, num_hiddens, num_layers=num_layers, bidirectional=True)
        self.decoder = nn.Linear(4 * num_hiddens, 2)

    def forward(self, inputs):
        # inputs.shape: (batch_size, time_steps)
        # outputs.shape: (time_steps, batch_size, embed_size)

        embeddings = self.embedding(inputs.T)
        self.encoder.flatten_parameters()  # 将参数重新排列为连续内存布局

        outputs, _ = self.encoder(embeddings)
        
        encoding = torch.cat((outputs[0], outputs[-1]), dim=1)
        outputs = self.decoder(encoding)

        return outputs
    
class RNNTextClassifier(nn.Module):
    def __init__(self, inp_size, hidden_size, n_class, layer_num, vocab_len, device):
        super(RNNTextClassifier, self).__init__()
        
        self.embedding = nn.Embedding(vocab_len, inp_size)
        self.device = device
        self.hidden_size = hidden_size
        self.layer_num = layer_num
        self.rnn = nn.RNN(input_size=inp_size, hidden_size=hidden_size, num_layers=layer_num, batch_first=True)
        self.fc = nn.Linear(hidden_size, n_class, bias=True)

    def forward(self, x):

        x_embed = self.embedding(x)
        outputs, hidden = self.rnn(x_embed)
        last_hidden = hidden[-1].squeeze(0)
        outputs = self.fc(last_hidden)

        return outputs

    def forward_bak(self, x):
        x_embed = self.embedding(x)
        b_s, s_l, e_s = x_embed.shape

        hidden_init = self.init_hidden(b_s)
        outputs, hidden = self.rnn(x_embed, hidden_init)
        last_hidden = hidden[-1].squeeze(0)
        outputs = self.fc(last_hidden)

        return outputs


    def init_hidden(self, batch_size):
        hidden = torch.zeros(self.layer_num, batch_size, self.hidden_size)
        hidden = hidden.to(self.device)
        return hidden
