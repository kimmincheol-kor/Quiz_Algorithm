from collections import deque
from sys import stdin

# Input
N, M, K, X = map(int, stdin.readline().split())
edges = [[] for _ in range(N+1)]
for _ in range(M):
    A, B = map(int, stdin.readline().split())
    edges[A].append(B)

# Distance From X
lenPath = [-1] * (N+1)
lenPath[X] = 0
queue = deque([X])

# BFS
while queue:
    node = queue.popleft()
    for n in edges[node]:
        if lenPath[n] == -1:
            queue.append(n)
            lenPath[n] = lenPath[node] + 1

# Result
flag = False
for i in range(1, N+1):
    if lenPath[i] == K:
        print(i)
        flag = True
if flag == False:
    print(-1)