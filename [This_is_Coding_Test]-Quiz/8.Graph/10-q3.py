from collections import deque

# Input and Initialize
n = int(input())

graph = [[] for _ in range(n+1)]

indegree = [0] * (n+1)
timeTable = [0] * (n+1)
resultTable = [0] * (n+1)

# Input Edge Data
for i in range(1, n+1):
    line = list(map(int, input().split()))
    
    timeTable[i] = line[0]
    
    for j in range(1, len(line)):
        if line[j] != -1:
            graph[line[j]].append(i)
            indegree[i] += 1

# Topoogy Sort
q = deque()

for i in range(1, n+1):
    if indegree[i] == 0:
        resultTable[i] = timeTable[i]
        q.append(i)

while q:
    curNode = q.popleft()
    
    for adjNode in graph[curNode]:
        indegree[adjNode] -= 1
        if indegree[adjNode] == 0:
            q.append(adjNode)
        if resultTable[adjNode] < timeTable[adjNode] + resultTable[curNode]:
            resultTable[adjNode] = timeTable[adjNode] + resultTable[curNode]

# Result
print(resultTable)