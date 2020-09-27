def checkCorrect():
    global n
    global sMap

    for i in range(n):
        for j in range(n):
            if sMap[i][j] == 'T':
                # Up
                if i > 0:
                    for p in range(i-1,-1,-1):
                        if sMap[p][j] == 'O':
                            break
                        if sMap[p][j] == 'S':
                            return False

                # Down
                if i < n-1:
                    for p in range(i+1, n):
                        if sMap[p][j] == 'O':
                            break
                        if sMap[p][j] == 'S':
                            return False

                # Left
                if j > 0:
                    for p in range(j-1, -1, -1):
                        if sMap[i][p] == 'O':
                            break
                        if sMap[i][p] == 'S':
                            return False

                # Right
                if j < n-1:
                    for p in range(j+1, n):
                        if sMap[i][p] == 'O':
                            break
                        if sMap[i][p] == 'S':
                            return False

    return True

def dfs(cnt):
    global n
    global sMap

    if cnt == 3:
        return checkCorrect()
    else:
        for i in range(n):
            for j in range(n):
                if sMap[i][j] == 'X':
                    sMap[i][j] = 'O'
                    if dfs(cnt+1):
                        return True
                    sMap[i][j] = 'X'

    if cnt == 0:
        return False

n = int(input())
sMap = []
for _ in range(n):
    data = list(input().split())
    sMap.append(data)

if dfs(0):
    print("YES")
else:
    print("NO")