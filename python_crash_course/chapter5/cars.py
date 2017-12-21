#!/usr/bin/python3

cars = ['audi', 'bmw', "subaru", "toyota"]

for car in cars:
    if car == "bmw":    #判断字符串相等，与c截然不同
        print(car.upper())
    else:
        print(car.title())
