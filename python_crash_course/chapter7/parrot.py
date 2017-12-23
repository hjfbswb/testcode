#!/usr/bin/python3

# -*- coding:utf-8 -*-

while 1:
    msg = input("我将重复你输入的东西（输入quit结束）：")
    if 'quit' == msg or 'q' == msg:
        break

    print("你输入的是：" + msg)

