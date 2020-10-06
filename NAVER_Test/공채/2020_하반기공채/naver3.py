minVirus = 51

def dfs(adjList, cnt, nodes):
    global minVirus

    print(cnt , nodes)

    allChild = []

    for node in nodes:
        allChild.extend(adjList[node])

    print(allChild)

    if len(allChild) == 0:
        if cnt < minVirus:
            
            minVirus = cnt
            print("Update !!", minVirus)
    else:
        for node in allChild:
            newNodes = []
            for i in allChild:
                if i != node:
                    newNodes.append(i)

            dfs(adjList, cnt+len(newNodes), newNodes)

def solution(n, edges):
    global minVirus

    adjList = [[] for _ in range(n)]
    for edge in edges:
        adjList[edge[0]].append(edge[1])

    dfs(adjList, 1, [0])

    return minVirus
    

if __name__ == "__main__":
    n = 19
    edges = [[0, 1], [0, 2], [0, 3], [1, 4], [1, 5], [2, 6], [3, 7], [3, 8], [3, 9], [4, 10], [4, 11], [5, 12], [5, 13], [6, 14], [6, 15], [6, 16], [8, 17], [8, 18]]

    print(solution(n, edges))