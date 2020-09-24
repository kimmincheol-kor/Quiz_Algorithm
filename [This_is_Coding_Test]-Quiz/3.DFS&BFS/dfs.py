def dfs(graph, v, visited):
    visited[v] = True # 방문 처리
    print("visited : ", v)

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

#######################################################            

# adjacency list
graph = [[] for _ in range(5)]
visited1 = [False for _ in range(5)]

graph[0].append(1)
graph[1].append(0)

# adjacency matrix
matrix = [[0 for _ in range(5)] for _ in range(5)]
visited2 = [False] * 5

matrix[0][1] = 1
matrix[1][0] = 1

visited2[0] = True

##########################################################

# recursive
dfs(graph, 0, visited1)