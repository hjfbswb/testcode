
alien_0 = {'color': 'green', 'points': 5}

print(alien_0['color'])
print(alien_0['points'])

dict_0 = {} #一个空字典
print(dict_0)

dict_1 = {"name": "hjfbswb"} #只有一个键值对的字典
print(dict_1)

dict_2 = {"name": "hjfbswb", "sex": "man"} #含有2个键值对的字典
print(dict_2)

person = {"height": 171} #定义了一个字典
person['weight'] = 60 #由于'weight'这个键在字典person中本来不存在，所以该行代码会向person中添加一个键值对
person['height'] = 180 #由于'height'这个键在字典person中本来就存在，所以该行代码会修改person中的'height'键对应的值
print(person)

del person['height'] #使用del语句删除键值对时，需要指定字典和键。
print(person)
