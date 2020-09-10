import sys

data = list(sys.stdin.readline().rstrip())

for i, val in enumerate(data):
    data[i] = int(val)

flag = data[0]
cnt = 0

# Count Different Number
for i in data:
    if(i != flag):
        flag = i
        cnt += 1

print(cnt-1)