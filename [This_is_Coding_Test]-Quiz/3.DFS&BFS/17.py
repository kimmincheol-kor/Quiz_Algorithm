from collections import deque

def bfs(vMap, queue, n):
    length = len(queue)

    # Pop length datas From Queue
    for _ in range(length):
        point = queue.popleft()
        vNum = point[0]
        py = point[1]
        px = point[2]

        # Up
        if py > 0 and vMap[py-1][px] == 0:
            vMap[py-1][px] = vNum
            queue.append((vNum, py-1, px))

        # Down
        if py < n-1 and vMap[py+1][px] == 0:
            vMap[py+1][px] = vNum
            queue.append((vNum, py+1, px))

        # Left
        if px > 0 and vMap[py][px-1] == 0:
            vMap[py][px-1] = vNum
            queue.append((vNum, py, px-1))

        # Right
        if px < n-1 and vMap[py][px+1] == 0:
            vMap[py][px+1] = vNum
            queue.append((vNum, py, px+1))

# Input
n, k = map(int, input().split())
vMap = []
for _ in range(n):
    inputLine = list(map(int, input().split()))
    vMap.append(inputLine)
s, x, y = map(int, input().split())

# Create Queue For Virus
tempq = []
for i in range(n):
    for j in range(n):
        if vMap[i][j] > 0:
            tempq.append((vMap[i][j], i, j))

tempq.sort()
queue = deque(tempq)

# Progress in every Sec
for sec in range(1, s+1):
    if not queue:
        break
    bfs(vMap, queue, n)

# Get Result
print(vMap[x-1][y-1])