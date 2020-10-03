# 7-5 => Using Set

n = int(input())
# set
nList = set(map(int, input().split()))

m = int(input())
mList = list(map(int, input().split()))

for item in mList:
    if item in nList:
        print("yes", end=" ")
    else:
        print("no", end=" ")