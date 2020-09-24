from collections import deque

# adjacency list
graph = [[] for _ in range(5)]
visited = [False for _ in range(5)]

graph[0].append(1)
graph[1].append(0)

# adjacency matrix
matrix = [[0 for _ in range(5)] for _ in range(5)]

matrix[0][1] = 1
matrix[1][0] = 1

visited[0] = True

##########################################################

queue = deque([0])

while queue:
    node = queue.popleft()

    for i in graph[node]:
        if not visited[i]:
            queue.append(i)
            visited[i] = True