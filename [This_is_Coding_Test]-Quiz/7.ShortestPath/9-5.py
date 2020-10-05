# Message

import heapq
import sys
input = sys.stdin.readline

INF = int(1e9)

# Input Number of Nodes, Edges
n, m, c = map(int, input().split())

# Initailize
graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

# Input Graph Data
for _ in range(m):
    src, dist, w = map(int, input().split())
    graph[src].append((dist, w))

def dijkstra(start):
    distance[start] = 0

    heap = []
    heapq.heappush(heap, (0, start))

    while heap:
        curDistance, curNode = heapq.heappop(heap)

        if distance[curNode] < curDistance:
            continue

        for adjNode in graph[curNode]:
            cost = curDistance + adjNode[1]

            if cost < distance[adjNode[0]]:
                distance[adjNode[0]] = cost
                heapq.heappush(heap, (cost, adjNode[0]))

dijkstra(c)

longestNode = 0
numNode = -1

for i in range(1, n+1):
    if distance[i] < INF:
        numNode += 1
        if distance[i] > longestNode:
            longestNode = distance[i]

print(numNode, longestNode)