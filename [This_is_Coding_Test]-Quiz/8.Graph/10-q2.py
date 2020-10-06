import sys
input = sys.stdin.readline

def getParent(pTable, x):
    if pTable[x] != x:
        pTable[x] = getParent(pTable, pTable[x])
    return pTable[x]

n, m = map(int, input().split())

edges = []

pTable = [0]
for i in range(1, n+1):
    pTable.append(i)

for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))

edges.sort()
result = []

for edge in edges:
    cost, a, b = edge

    aP = getParent(pTable, a)
    bP = getParent(pTable, b)

    # no cycle -> Union
    if aP != bP:
        result.append(cost)
        if aP < bP:
            pTable[bP] = aP
        else:
            pTable[aP] = bP

# Result
dividePath = max(result)
print(sum(result) - dividePath)