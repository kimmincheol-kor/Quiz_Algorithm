N = input()
data = list(map(int, input().split()))

# number of total group
result = 0
# number of members of current group
cnt = 0

data.sort()

# Count Num of Group
for a in data:
    cnt+=1
    if(cnt == a): # Done of Making a group
        result+=1
        cnt=0

print(result)