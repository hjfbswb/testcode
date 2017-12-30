
def greet_users(names):
    """向列表中的所有用户问候"""
    for name in names:
        print("Hello, " + name.title() + "!")

usernames = ['lxd', "edward", "mari"]
greet_users(usernames)
