from itertools import combinations
import copy

def countSafety(vMap, n, m):

    virusStack = []

    for i in range(n):
        for j in range(m):
            # Virous !
            if vMap[i][j] == 2:
                virusStack.append((i,j))

    while virusStack:
        node = virusStack.pop()
        y = node[0]
        x = node[1]

        # Up
        if y > 0 and vMap[y-1][x] == 0:
            vMap[y-1][x] = 2
            virusStack.append((y-1, x))

        # Down
        if y < n-1 and vMap[y+1][x] == 0:
            vMap[y+1][x] = 2
            virusStack.append((y+1, x))

        # Left
        if x > 0 and vMap[y][x-1] == 0:
            vMap[y][x-1] = 2
            virusStack.append((y, x-1))

        # Right
        if x < m-1 and vMap[y][x+1] == 0:
            vMap[y][x+1] = 2
            virusStack.append((y, x+1))

    cnt = 0

    for i in range(n):
        for j in range(m):
            if vMap[i][j] == 0:
                cnt += 1

    return cnt

n, m = map(int, input().split())
vMap = []
for _ in range(n):
    line = list(map(int, input().split()))
    vMap.append(line)

# List of Position of Zero
zeroPos = []
for i in range(n):
    for j in range(m):
        if vMap[i][j] == 0:
            zeroPos.append((i,j))

# Get All Combinations of 3
allComb = list(combinations(zeroPos, 3))

# Count Safety Zone
maxSafety = 0

# Check All Combinaions
for combs in allComb:
    c1 = combs[0]
    c2 = combs[1]
    c3 = combs[2]

    # copy and install wall
    copyMap = copy.deepcopy(vMap)
    copyMap[c1[0]][c1[1]] = 1
    copyMap[c2[0]][c2[1]] = 1
    copyMap[c3[0]][c3[1]] = 1

    cnt = countSafety(copyMap, n, m)

    if maxSafety < cnt:
        maxSafety = cnt

# Result
print(maxSafety)