#!/usr/bin/python3

# -*- coding:utf-8 -*-

s = ['b', 'a', 'c', 'd']
print("origin", s)

s.sort() #列表的sort()方法会正序排列列表中的元素，sort()方法会永久改变列表中元素的顺序
print('after sort()', s)
s.sort(reverse=True) #参数reverse=True时，sort()方法会逆序排列列表中的元素
print('after sort(reverse=True)', s)

s = ['b', 'a', 'c', 'd']
print("origin", s)

print("sorted()", sorted(s)) #sorted()函数返回一个正序排列的临时表，sorted()函数不会改变列表中的元素顺序
print("sorted(reverse=True)", sorted(s, reverse=True)) #参数reverse=True时，sorted()函数返回一个逆序排列的临时表，sorted()函数不会改变列表中的元素顺序

s.reverse()
print('reverse()', s) #reverse()方法会反转列表中的元素顺序，会永久改变列表中元素的顺序
s.reverse()
print('reverse() again', s) #连续调用2次reverse()方法，列表的顺序会恢复到原来

print('len', len(s)) #len()函数能够计算出列表的长度


