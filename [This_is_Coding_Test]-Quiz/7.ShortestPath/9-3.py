# Floyd-Warshall Algorithm

import sys
input = sys.stdin.readline

INF = int(1e9)

# Input Number of Nodes, Edges
n, e = map(int, input().split())

# Initialize distance graph
distance = [[INF] * (n+1) for _ in range(n+1)]

for i in range(1, n+1):
    distance[i][i] = 0

# Input Graph Data
for _ in range(e):
    src, dist, w = map(int, input().split())
    distance[src][dist] = w

def floydWarshall():
    for step in range(1, n+1):
        for src in range(1, n+1):
            for dist in range(1, n+1):
                distance[src][dist] = min(distance[src][dist], distance[src][step] + distance[step][dist])

floydWarshall()

print(distance)