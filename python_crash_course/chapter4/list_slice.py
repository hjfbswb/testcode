#!/usr/bin/python3

# -*- coding:utf-8 -*-

nums = [110, 119, 120, 10086, 10000]

print("list:\n\t", nums)
print("\nslice[0:3]:\n\t", nums[0:3]) #切片，包含索引为0，1，2的这三个元素，不包含索引为3的元素
print("\nslice[1:4]:\n\t", nums[1:4]) #切片，包含第2个到第4个元素。
print("\nslice[:4]:\n\t", nums[:4]) #切片缺省从第1个元素开始
print("\nslice[2:]:\n\t", nums[2:]) #切片缺省到最后一个元素结束
print("\nslice[-2:]:\n\t", nums[-2:]) #生成切片时可以使用负索引
print("\nslice[:]:\n\t", nums[:], "\n") #起始索引和结束索引都缺省，相当于复制了原来的列表


persons = ['edward', 'lxd', 'liuheng', 'hjfbswb']
for person in persons[1:3]:
    print("inter slice", person)



