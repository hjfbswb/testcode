
def print_models(todo, done):
    """对todo列表中的所有作品进行打印，打印好的放到done里"""
    while todo:
        next = todo.pop(0)
        print("printing " + next + "...")
        done.append(next)

def show_models(models):
    for m in models:
        print("model: " + m)

