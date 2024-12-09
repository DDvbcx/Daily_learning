import re
import os 
from tqdm import tqdm
import numpy as np
from typing import List, Tuple, Dict
import matplotlib.pyplot as plt


# 数据清洗规则
def text_split(content: str) -> List[str]:
    '''
    对于原始文本进行 token 化，以及一系列预处理清洗操作

    '''
    content = re.sub(r"([.!?])", r" \1", content)
    content = re.sub(r"[^a-zA-Z.!?]+", r" ", content)  # 去除掉不是大小写字母及 .!? 符号的数据
    token = [i.strip().lower() for i in content.split()]  # 全部转换为小写，然后去除两边空格，将字符串转换成list
    return token  

def plot_word_frequency(word_count_dict, hist_size=100):
    words = list(word_count_dict.keys())[:hist_size]
    frequencies = list(word_count_dict.values())[:hist_size]

    plt.figure(figsize=(10, 6))
    plt.bar(words, frequencies)
    plt.title('Word Frequency')
    plt.xlabel('Words')
    plt.ylabel('Frequency')
    plt.xticks(rotation=90)
    path_out = 'word_frequency.jpg'
    plt.savefig(path_out)
    print(f'保存词频统计图:{path_out}')   


class Vocabulary:
    UNK_TAG = "UNK"   
    PAD_TAG = "PAD"
    UNK = 0
    PAD = 1

    def __init__(self):
        self.inverse_vocab = None
        self.vocabulary = {self.UNK_TAG: self.UNK, self.PAD_TAG: self.PAD}
        self.count = {}

    def fit(self, sentence_: List[str]):
        '''
        统计词频
        '''
        for word in sentence_:
            self.count[word] = self.count.get(word, 0) + 1
    
    def build_vocab(self, min=0, max=None, max_vocab_size=None) -> Tuple[dict, dict]:

        # 词频截断，词频大于或者小于一定数值时，舍弃
        if min is not None:
            self.count = {word: value for word, value in self.count.items() if value > min}
        if max is not None:
            self.count = {word: value for word, value in self.count.items() if value < max}
        
        # 选择词表大小，根据词频排序后截断
        if max_vocab_size is not None:
            raw_len = len(self.count.items())
            vocab_size = max_vocab_size if raw_len > max_vocab_size else raw_len
            print(f"原始词表长度:{raw_len}，截断后长度:{vocab_size}")
            temp = sorted(self.count.items(), key=lambda x: x[1], reverse=True)[:vocab_size]
            self.count = dict(temp)
        
        # 建立词表: token -> index
        for word in self.count:
            self.vocabulary[word] = len(self.vocabulary)
        
        # 词表反转
        self.inverse_vocab = dict(zip(self.vocabulary.values(), self.vocabulary.keys()))

    def __len__(self):
        return len(self.vocabulary)

if __name__ == '__main__':
    max_vocab_size = 20000
    path = ''
    BASE_DIR = os.path.dirname(__file__)
    out_dir = os.path.join(BASE_DIR, "result")
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    vocab_path = os.path.join(out_dir, "aclImdb_vocab.npy")
    vocab_inv_path = os.path.join(out_dir, "aclImdb_vocab_inv.npy")

    # 统计词频
    vocab_hist = Vocabulary()
    temp_data_path = [os.path.join(path, "pos"), os.path.join(path, "neg")]
    for data_path in temp_data_path:
        file_paths = [os.path.join(data_path, file_name) for file_name in os.listdir(data_path) if file_name.endswith("txt")]
        for file_path in tqdm(file_paths):
            sentence = text_split(open(file_path, encoding='utf-8').read())
            vocab_hist.fit(sentence)
    
    # 建立词表
    vocab, inverse_vocab = Vocabulary.build_vocab(max_vocab_size=(max_vocab_size - 2))

    np.save(vocab_path, vocab)
    np.save(vocab_inv_path, inverse_vocab)

    # 词表、词频可视化
    print(len(vocab))
    word_count = vocab_hist.count
    plot_word_frequency(word_count)

