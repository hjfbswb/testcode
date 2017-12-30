
with open("pi.txt") as f:
    cont = f.read()
    print(cont.rstrip())

print()

with open("pi.txt") as f:
    for line in f:
        print(line.rstrip())

print()

with open("pi.txt") as f:
    lines = f.readlines()

pi_string = ""
for line in lines:
    pi_string += line.strip()

print(pi_string)
print(len(pi_string))

