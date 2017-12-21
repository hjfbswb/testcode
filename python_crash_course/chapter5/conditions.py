#!/usr/bin/python3

car = "audi"

print("******compare strings******")

print("true: ", car == "audi")
print("false: ", car == "bmw")

print("false: ", car != "audi")
print("true: ", car != "bmw")


print("\n******compare numbers******")

n = 10

print("true: ", n == 10)
print("false: ", n == 11)

print("false: ", n != 10)
print("true: ", n != 11)

print("true: ", n > 5)
print("false: ", n > 15)

print("true: ", n < 15)
print("false: ", n < 5)

print("true: ", n >= 5)
print("false: ", n >= 15)

print("true: ", n <= 15)
print("false: ", n <= 5)

print("\n******use and or******")

n = 10
m = 20

print("true: ", n >= 10 and m >= 20)
print("false: ", n < 0 and m >= 20)

print("true: ", n >= 10 or m < 20)
print("false: ", n > 10 or m < 20)

print("\n******use in******")

nums = [1, 2, 3, 4]

print("true: ", 1 in nums)
print("false: ", 5 in nums)

print("\n******use not in******")

nums = [5, 6, 7, 8]

print("true: ", 1 not in nums)
print("false: ", 5 not in nums)

