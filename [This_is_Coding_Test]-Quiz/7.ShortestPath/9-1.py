# Simple Dijkstra Algorithm

import sys
input = sys.stdin.readline

INF = int(1e9)

# Input Number of Nodes, Edges
n, e = map(int, input().split())
start = int(input())

# Initailize
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)
distance = [INF] * (n+1)

# Input Graph Data
for _ in range(e):
    src, dist, w = map(int, input().split())
    graph[src].append((dist, w))

def getSmallestNode():
    minValue = INF
    index = 0

    # Find Node that has Smallest Distance
    # Linear Search = O(V)
    for i in range(1, n+1):
        if distance[i] < minValue and not visited[i]:
            minValue = distance[i]
            index = i
    
    return index

def dijkstra(start):
    distance[start] = 0
    visited[start] = True

    for adjNode in graph[start]:
        distance[adjNode[0]] = adjNode[1]

    # Visit All Node of Graph, Update Distance
    # All Node = O(V)
    for _ in range(n-1):
        curNode = getSmallestNode() # O(V)
        visited[curNode] = True

        for adjNode in graph[curNode]: # O(V)
            cost = distance[curNode] + adjNode[1]
            if cost < distance[adjNode[0]]:
                distance[adjNode[0]] = cost

dijkstra(start)

print(distance)