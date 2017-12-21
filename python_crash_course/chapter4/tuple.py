#!/usr/bin/python3

# -*- coding:utf-8 -*-

four_num = (1, 2, 3, 4) #定义元组使用圆括号和逗号

for num in four_num:    #可以像遍历列表一样遍历元组
    print(num)

#four_num[1] = 5 #给元组中元素赋值是不可以的

four_num = (6, 8, 8, 6) #但是，可以给存储元组的变量重新赋值
print(four_num)
