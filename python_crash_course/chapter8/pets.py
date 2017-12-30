#!/usr/bin/python3

def describe_pet(animal_type, pet_name):
    """描述你的宠物：种类和名字"""
    print("I have a " + animal_type + 
        ", and it's name is " + pet_name + ".")

describe_pet("dog", "cony")     #位置实参

describe_pet(pet_name = "cony", animal_type = "dog") #关键字实参
describe_pet(animal_type = "dog", pet_name = "cony") #关键字实参

print("\n\n")

def describe_pet_ex(pet_name, animal_type = "dog"):
    """描述你的宠物：种类和名字"""
    print("I have a " + animal_type + 
        ", and it's name is " + pet_name + ".")

describe_pet_ex("阿财")
describe_pet_ex(pet_name = "阿财")
describe_pet_ex("小美", "cat")
describe_pet_ex(animal_type = "cat", pet_name = "小美")
describe_pet_ex(pet_name = "小美", animal_type = "cat")

