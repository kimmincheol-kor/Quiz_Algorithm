# Kruskal Algorithm for MST

def find_parent(pTable, x):
    if pTable[x] != x:
        pTable[x] = find_parent(pTable, pTable[x])
    return pTable[x]

def union_node(pTable, a, b):
    a = find_parent(pTable, a)
    b = find_parent(pTable, b)
    if a < b:
        pTable[b] = a
    else:
        pTable[a] = b

v, e = map(int, input().split())
pTable = [0]
for i in range(1, v+1):
    pTable.append(i)

# Variables For MST
edges = []
result = 0

# Get Edge Datas
for _ in range(e):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))

# Sort by Cost 
edges.sort()

for edge in edges:
    cost, a, b = edge

    # No Cycle
    if find_parent(pTable, a) != find_parent(pTable, b):
        union_node(pTable, a, b)
        result += cost

print(result)