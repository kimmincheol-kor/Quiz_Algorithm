# Topology Sort

from collections import deque

v, e = map(int, input().split())

indegree = [0] * (v+1)
graph = [[] for _ in range(1, v+1)]

for _ in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

def topology_sort():
    result = []
    q = deque()

    # Push to Queue indegree=0 Nodes
    for i in range(1, v+1):
        if indegree[i] == 0:
            q.append(i)

    while q:
        curNode = q.popleft()
        result.append(curNode)

        # Delete Edge that Started From curNode
        for adjNode in graph[curNode]:
            indegree[adjNode] -= 1
            if indegree[adjNode] == 0:
                q.append(adjNode)

    if len(result) < v:
        print("cycle")
    else:
        print(result)

topology_sort()


