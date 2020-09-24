N = 4
M = 5
data = [[0,0,1,1,0],[0,0,0,1,1],[1,1,1,1,1],[0,0,0,0,0]]

# dfs Function
def dfs(row, col):
    data[row][col] = 1

    # Right
    if col < M-1 and data[row][col+1] == 0:
        dfs(row, col+1)
    # Bottom
    if row < N-1 and data[row+1][col] == 0:
        dfs(row+1, col)

result = 0

for row in range(N):
    for col in range(M):
        # Find New 0
        if data[row][col] == 0:
            dfs(row, col)
            result += 1

print(result)