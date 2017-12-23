#!/usr/bin/python3

list_in_dict = {
    'num': [1, 2, 3], 
    'str': ["a", 'b', 'c'], 
    'float': [0.1, 0.2, 0.3]
    }

print(list_in_dict)

list_in_dict['num'].append(4)
del list_in_dict['str'][0]
list_in_dict['float'][0] = 0.0
print(list_in_dict)

