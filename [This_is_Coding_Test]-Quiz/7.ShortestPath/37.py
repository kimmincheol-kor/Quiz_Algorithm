import sys
input = sys.stdin.readline
INF = int(1e9)

n = int(input())
m = int(input())

distance = [[INF] * (n+1) for _ in range(n+1)]
for i in range(1, n+1):
    distance[i][i] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    if distance[a][b] > c: 
        distance[a][b] = c

# Floyd-Warshall Algorithm
for step in range(1, n+1):
    for src in range(1, n+1):
        for dist in range(1, n+1):
            distance[src][dist] = min(distance[src][dist], distance[src][step] + distance[step][dist])

# Result
for i in range(1, n+1):
    for j in range(1, n+1):
        if distance[i][j] == INF:
            print(0, end=" ")
        else:
            print(distance[i][j], end=" ")
    print()