#!/usr/bin/python3

def format_name(first, last, middle = ""):
    "返回一个格式化的名字"
    if middle:
        name = first + " " + middle + " " + last
    else:
        name = first + " " + last
    
    return name.title()

while True:
    first = input("first name: ")
    if first == "q":
        break
    
    last = input("last name: ")
    if last == "q":
        break

    print("Hello, " + format_name(first, last) + ".")
