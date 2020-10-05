# Advanced Dijkstra Algorithm

import heapq
import sys
input = sys.stdin.readline

INF = int(1e9)

# Input Number of Nodes, Edges
n, e = map(int, input().split())
start = int(input())

# Initailize
graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

# Input Graph Data
for _ in range(e):
    src, dist, w = map(int, input().split())
    graph[src].append((dist, w))

def dijkstra(start):
    distance[start] = 0

    heap = []
    heapq.heappush(heap, (0, start))

    while heap: # All Edges = O(E)
        curDistance, curNode = heapq.heappop(heap)

        # Ignore : Visited Node
        if distance[curNode] < curDistance:
            continue

        for adjNode in graph[curNode]: # include in O(E)
            cost = curDistance + adjNode[1]

            if cost < distance[adjNode[0]]:
                distance[adjNode[0]] = cost
                heapq.heappush(heap, (cost, adjNode[0])) # insert to Heap = O(log V)

dijkstra(start)

print(distance)