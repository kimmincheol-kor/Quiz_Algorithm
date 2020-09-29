from collections import deque

n, l, r = map(int, input().split())
wMap = []
for _ in range(n):
    new_line = list(map(int, input().split()))
    wMap.append(new_line)

# Count for Moving of People
for count in range(2001):    
    queue = deque()
    group = []
    visited = [[False]*n for _ in range(n)]

    # Make Group
    for i in range(n):
        for j in range(n):
            if visited[i][j] == False:
                queue.append((i,j))
                visited[i][j] = True
                new_group = [(i,j)]

                # BFS
                while queue:
                    cur = queue.popleft()

                    row = cur[0]
                    col = cur[1]

                    # Up
                    if row > 0 and visited[row-1][col] == False and abs(wMap[row-1][col]-wMap[row][col]) >= l and abs(wMap[row-1][col]-wMap[row][col]) <= r :
                        queue.append((row-1, col))
                        visited[row-1][col] = True

                        new_group.append((row-1, col))

                    # Down
                    if row < n-1 and visited[row+1][col] == False and abs(wMap[row+1][col]-wMap[row][col]) >= l and abs(wMap[row+1][col]-wMap[row][col]) <= r :
                        queue.append((row+1, col))
                        visited[row+1][col] = True

                        new_group.append((row+1, col))

                    # Left
                    if col > 0 and visited[row][col-1] == False and abs(wMap[row][col-1]-wMap[row][col]) >= l and abs(wMap[row][col-1]-wMap[row][col]) <= r :
                        queue.append((row, col-1))
                        visited[row][col-1] = True

                        new_group.append((row, col-1))

                    # Right
                    if col < n-1 and visited[row][col+1] == False and abs(wMap[row][col+1]-wMap[row][col]) >= l and abs(wMap[row][col+1]-wMap[row][col]) <= r :
                        queue.append((row, col+1))
                        visited[row][col+1] = True

                        new_group.append((row, col+1))

                if len(new_group) > 1:
                    group.append(new_group)

    # Move Peoples
    if len(group) == 0:
        print(count)
        break
    else:
        for each_group in group:
            
            sum_people = 0
            sum_country = len(each_group)

            for c in each_group:
                sum_people += wMap[c[0]][c[1]]

            # Avg of Group
            avg = sum_people // sum_country

            for c in each_group:
                wMap[c[0]][c[1]] = avg
