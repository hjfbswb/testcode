
#python中可以将字典定义分到多行
user_0 = {
    'username': 'efermi', 
    'first': 'enrico', 
    'last': 'fermi', 
    }

#字典的items()方法会返回一个键值对列表，其中包含该字典中的所有键值对。
for k, v in user_0.items():
    print('\nkey: ' + k)
    print('value: ' + v)

#字典的keys()方法会返回一个包含字典中所有键的列表
for k in user_0.keys():
    print('\nkey: ' + k)

#遍历字典时，默认是遍历字典中的键，所以遍历字典中的键时，可以不调用keys()方法
for k in user_0:
    print('\nkey: ' + k)

#字典的values()方法会返回一个包含字典中所有值的列表
for v in user_0.values():
    print("\nvalue:" + v)

dict3 = {'name': 'hjfbswb', 'blog': 'hjfbswb', 'sex': 'man'}

for v in dict3.values():
    print('no set value: ' + v)

for v in set(dict3.values()):
    print('with set value: ' + v)

