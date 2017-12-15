
# -*- coding:utf-8 -*-

name = "ada lovelace"

print("title()", name.title()) #title()方法能够将每个单词的首字母变成大写，其他字母变成小写。
print("upper()", name.upper()) #upper()方法能够将字符串里所有的字母都变成大写。
print("lower()", name.lower()) #lower()方法能够将字符串里所有的字母都变成小写。

love = "\t Python\t "
print("lstrip() (%s)" % love.lstrip()) #lstrip()方法删除字符串开头的空白
print("rstrip() (%s)" % love.rstrip()) #rstrip()方法删除字符串结尾的空白
print("strip() (%s)" % love.strip()) #strip()方法删除字符串两端的空白

love = love.strip() #love变量被覆盖了，所以永久改变
print("love变量被永久的变为了(%s)" % love)
