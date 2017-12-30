

def count_words(filename):
    """计算一个文件中包含多少个单词"""
    try:
        with open(filename) as f:
            cont = f.read()
    except FileNotFoundError:
        msg = "Sorry, file{" + filename+ "} does not exist."
        print(msg)
    else:
        words = cont.split()
        num = len(words)
        print("The file " + filename + " has about " + str(num) + " words.")


filenames = ["alice.txt", "noexist", "count_words.py", "division.py", "file_reader.py", "pi.txt"]
for fn in filenames:
    count_words(fn)
