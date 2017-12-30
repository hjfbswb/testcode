
def format_name(first, last, middle=''):
    """输入first name和last name，输出一个格式化好的名字"""

    if middle:
        full_name = first + " " + middle + " " + last
    else:
        full_name = first + " " + last
        
    return full_name.title()

