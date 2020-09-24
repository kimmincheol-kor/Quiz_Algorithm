from collections import deque

# Input Data
N=3
M=3
miro = [[1,1,0], [0,1,0], [0,1,1]]

# min Distance From Start Point
minDistance = [[100000]*M for _ in range(N)]

# Set Start Point
queue = deque([(0,0)])
minDistance[0][0] = 1

while queue:
    node = queue.popleft()

    # Right
    if node[1] < M-1 and miro[node[0]][node[1]+1] == 1:
        if minDistance[node[0]][node[1]+1] > minDistance[node[0]][node[1]] + 1:
            minDistance[node[0]][node[1]+1] = minDistance[node[0]][node[1]] + 1
            queue.append((node[0], node[1]+1))

    # Left
    if node[1] > 0 and miro[node[0]][node[1]-1] == 1:
        if minDistance[node[0]][node[1]-1] > minDistance[node[0]][node[1]] + 1:
            minDistance[node[0]][node[1]-1] = minDistance[node[0]][node[1]] + 1
            queue.append((node[0], node[1]-1))
        
    # Bottom
    if node[0] < N-1 and miro[node[0]+1][node[1]] == 1:
        if minDistance[node[0]+1][node[1]] > minDistance[node[0]][node[1]] + 1:
            minDistance[node[0]+1][node[1]] = minDistance[node[0]][node[1]] + 1
            queue.append((node[0]+1, node[1]))

    # Up
    if node[0] > 0 and miro[node[0]-1][node[1]] == 1:
        if minDistance[node[0]-1][node[1]] > minDistance[node[0]][node[1]] + 1:
            minDistance[node[0]-1][node[1]] = minDistance[node[0]][node[1]] + 1
            queue.append((node[0]-1, node[1]))

print(minDistance[N-1][M-1])
