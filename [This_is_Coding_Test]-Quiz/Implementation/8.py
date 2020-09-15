inp = input()

# Sum of Numbers
num = 0
# List of Characters
chars = []

# Seperate Digit and Alpha
for i in inp:
    if i.isdigit():
        num += int(i)
    else:
        chars.append(i)

# Result
chars.sort()
print(''.join(chars) + str(num))