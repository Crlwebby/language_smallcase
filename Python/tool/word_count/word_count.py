# coding=utf-8

import os
from collections import Counter
import jieba

os.chdir(os.path.dirname(__file__))

def save_file(file_name, content):
    fp = open(file_name,"w", encoding="utf-8")
    for word in content:
        fp.write(word+"\n")
    fp.close()

stopwords = [line.strip() for line in open("./Stop_words.txt",encoding="utf-8").readlines()]
with open('./三国之暴君颜良.txt') as f:
    words = f.read()

word_list = jieba.lcut(words)
save_file("test1.txt",word_list)
word_list_update = []
for word in word_list:
    if word in stopwords or word == '\n':
        continue
    else:
        word_list_update.append(word)
word_counts = Counter(word_list_update)

ans = word_counts.most_common()
for individual in ans:
    print(individual[0],individual[1])

