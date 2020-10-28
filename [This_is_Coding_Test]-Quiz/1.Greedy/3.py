data = list(input())

flag = data[0]
cnt = 0

# Count Different Number
for i in data[1:]:
    if(i != flag):
        flag = i
        cnt += 1

print((cnt+1)//2)