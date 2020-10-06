# Simple Union-Find Algorithm

# Find Parent of Node x
def find_parent(pTable, x):
    if pTable[x] != x:
        return find_parent(pTable, pTable[x])
    return pTable[x]

# Union Operation
def union_node(pTable, a, b):
    a = find_parent(pTable, a)
    b = find_parent(pTable, b)
    if a < b:
        pTable[b] = a
    else:
        pTable[a] = b

# Number of Nodes, Edges
v, e = map(int, input().split())
# Table of Parent Data
pTable = [0]
for i in range(1, v+1):
    pTable.append(i)

# Union
for i in range(e):
    a, b = map(int, input().split())
    union_node(pTable, a, b)

print(pTable)

