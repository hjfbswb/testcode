#!/usr/bin/python3

# -*- coding:utf-8 -*-

colors = ['红', '蓝', '黑']
print("origin", colors)

colors[2] = '绿' #修改第3个元素为'绿'
print("after modify", colors)

colors.append('黄') #使用append()方法，在列表末尾添加元素
print("after append", colors)

colors.insert(0, '白') #使用insert()方法，在列表开头插入元素
print("insert '白' at beginning", colors)

colors.insert(2, '棕') #使用insert()方法，在列表的索引2的位置插入元素
print('insert "棕" at index 2', colors)

del colors[2] #使用del语句删除指定索引的元素
print("after del elem at index 2", colors)

pp = colors.pop() #pop()方法默认删除列表的最后一个元素，并返回删除的元素的值
print("after pop()", colors)
print("value popped", pp)

pp = colors.pop(0) #pop()方法可以删除指定索引的元素，并返回删除的元素的值
print("after pop(0)", colors)
print("value popped", pp)

valtorm = '蓝'
colors.remove(valtorm) #remove()方法删除第一个包含指定值的元素
print("after remove()", colors)
