# Check Relatively Prime(coprime) by using Union-Find

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
flag_cycle = False

for i in range(e):
    a, b = map(int, input().split())

    # Cycle Condition.
    if find_parent(pTable, a) == find_parent(pTable, b):
        flag_cycle = True
        break
    # Not Cycle
    else:
        union_node(pTable, a, b)

if flag_cycle:
    print("cycle")
else:
    print("no cycle")