# Union-Find Algorithm + Path Compression

# Find Parent of Node x : Path Compression
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

# Union
for i in range(e):
    a, b = map(int, input().split())
    union_node(pTable, a, b)

print(pTable)

