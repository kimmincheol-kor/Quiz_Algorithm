def getParent(pTable, x):
    if x != pTable[x]:
        pTable[x] = getParent(pTable, pTable[x])
    return pTable[x]

def unionFind(pTable, a, b):
    a = getParent(pTable, a)
    b = getParent(pTable, b)
    if a<b:
        pTable[b] = a
    else:
        pTable[a] = b

# Input & Initailize
n, m = map(int, input().split())
wMap = []
for _ in range(n):
    line = list(map(int, input().split()))
    wMap.append(line)
plan = list(map(int, input().split()))

pTable = [0] * (n+1)
for i in range(1, n+1):
    pTable[i] = i

# Union Find
for i in range(n):
    for j in range(n):
        if wMap[i][j] == 1:
            unionFind(pTable, i+1, j+1)

# Check Can Trip or Not
flag_parent = getParent(pTable, plan[0])
for trip in plan:
    if flag_parent != getParent(pTable, trip):
        print("NO")
        flag_parent = 0
        break
print("YES")