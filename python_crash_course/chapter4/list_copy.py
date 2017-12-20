#!/usr/bin/python3

# -*- coding:utf-8 -*-

my_foods = ['noodle', "dumpling", "pizza"]
friend_foods = my_foods[:] #将我的食物列表复制了一份，作为朋友的食物列表

my_foods.append("lanzhou")
friend_foods.append("shaobing")

print("my foods:", my_foods)
print("friend foods:", friend_foods)



