import sys
input = sys.stdin.readline

k = int(input())
stack = []
for i in range(k):
    temp = int(input())
    if temp:
        stack.append(temp)
    else:
        stack.pop()
print(sum(stack))