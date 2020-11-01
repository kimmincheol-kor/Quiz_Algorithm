k = int(input())

stack = []

for i in range(k):
    temp = int(input())
    if temp == 0:
        stack.pop()
    else:
        stack.append(temp)

print(sum(stack))