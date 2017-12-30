
from name_tool import format_name

print("Enter first and last name, and you'll get a formatted full name.")
print("Enter 'q' to quit.\n")

while True:
    first = input("First name: ")
    if 'q' == first:
        break

    last = input("Last name: ")
    if 'q' == last:
        break

    full_name = format_name(first, last)
    print("Full name is " + full_name)

