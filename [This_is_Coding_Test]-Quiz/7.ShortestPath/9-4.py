# Future City

import sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())

distance = [[INF] * (n+1) for _ in range(n+1)]

for i in range(1, n+1):
    distance[i][i] = 0

for _ in range(m):
    src, dist = map(int, input().split())
    distance[src][dist] = 1
    distance[dist][src] = 1

x, k = map(int, input().split())

# Floyd-WarShall Algorithm
for step in range(1, n+1):
    for src in range(1, n+1):
        for dist in range(1, n+1):
            distance[src][dist] = min(distance[src][dist], distance[src][step] + distance[step][dist])

if distance[1][k] == INF or distance[k][x] == INF:
    print(-1)
else:
    print(distance[1][k] + distance[k][x])
