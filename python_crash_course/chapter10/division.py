
print("Give me two numbers, and I'll divide them.")
print("Enter 'q' to quit.")

while True:
    first = input("\nFirst number: ")
    if 'q' == first:
        break

    second = input("Second number: ")
    if 'q' == second:
        break

    try:
        answer = int(first) / int(second)
    except ZeroDivisionError:
        print("Second number shall not be zero!")
    except ValueError:
        print("Input must be an integer.")
    else:
        print("answer is " + str(answer))
