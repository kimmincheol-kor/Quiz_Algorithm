# Make Team

# Path Compression
def getParent(pTable, x):
    if pTable[x] != x:
        pTable[x] = getParent(pTable, pTable[x])
    return pTable[x]

# Main
n, m = map(int, input().split())

pTable = [0]
for i in range(1, n+1):
    pTable.append(i)

for _ in range(m):
    op, a, b = map(int, input().split())

    a = getParent(pTable, a)
    b = getParent(pTable, b)

    # Union
    if op == 0:
        if a < b:
            pTable[b] = a
        else:
            pTable[a] = b
    # Find
    elif op == 1:
        if a == b:
            print("YES")
        else:
            print("NO")
