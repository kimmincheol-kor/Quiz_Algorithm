from collections import deque

def solution(board):

    n = len(board)
    start_pos = ((0, 0), (0, 1))

    # Visited Dictionary
    visited = {}
    visited[((0,0),(0,1))] = True

    # Queue For BFS
    queue = deque()
    queue.append((start_pos, 0))

    # BFS
    while queue:
        robot = queue.popleft()

        pos = robot[0]
        cnt = robot[1]

        if pos[0] == (n-1, n-1) or pos[1] == (n-1, n-1):
            return cnt

	    # 1. Move Down
        if pos[0][0] < n-1 and pos[1][0] < n-1 and board[pos[0][0]+1][pos[0][1]] == 0 and board[pos[1][0]+1][pos[1][1]] == 0:
            next_pos = ( (pos[0][0]+1, pos[0][1]), (pos[1][0]+1, pos[1][1]) )
            if not visited.get(next_pos):
                visited[next_pos] = True
                queue.append((next_pos, cnt+1))
            
        # 2. Move Right
        if pos[0][1] < n-1 and pos[1][1] < n-1 and board[pos[0][0]][pos[0][1]+1] == 0 and board[pos[1][0]][pos[1][1]+1] == 0:
            next_pos = ( (pos[0][0], pos[0][1]+1), (pos[1][0], pos[1][1]+1) )
            if not visited.get(next_pos):
                visited[next_pos] = True
                queue.append((next_pos, cnt+1))
            
        # 3. Rotation
        # horizon
        if pos[0][0] == pos[1][0]:
            # Down
            if pos[0][0] < n-1 and board[pos[0][0]+1][pos[0][1]] == 0 and board[pos[1][0]+1][pos[1][1]] == 0:
                # right
                next_pos = ( (pos[1][0], pos[1][1]), (pos[1][0]+1, pos[1][1]) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))
                # left
                next_pos = ( (pos[0][0], pos[0][1]), (pos[0][0]+1, pos[0][1]) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))

            # Up
            if pos[0][0] > 0 and board[pos[0][0]-1][pos[0][1]] == 0 and board[pos[1][0]-1][pos[1][1]] == 0:
                # right
                next_pos = ( (pos[1][0]-1, pos[1][1]), (pos[1][0], pos[1][1]) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))
                # left
                next_pos = ( (pos[0][0]-1, pos[0][1]), (pos[0][0], pos[0][1]) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))

        # vertical
        else:
            # Right
            if pos[0][1] < n-1 and board[pos[0][0]][pos[0][1]+1] == 0 and board[pos[1][0]][pos[1][1]+1] == 0:
                # Down
                next_pos = ( (pos[1][0], pos[1][1]), (pos[1][0], pos[1][1]+1) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))
                # Up
                next_pos = ( (pos[0][0], pos[0][1]), (pos[0][0], pos[0][1]+1) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))

            # Left
            if pos[0][1] > 0 and board[pos[0][0]][pos[0][1]-1] == 0 and board[pos[1][0]][pos[1][1]-1] == 0:
                # Down
                next_pos = ( (pos[1][0], pos[1][1]-1), (pos[1][0], pos[1][1]) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))
                # Up
                next_pos = ( (pos[0][0], pos[0][1]-1), (pos[0][0], pos[0][1]) )
                if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))

        # 4. Move Left
        if pos[0][1] > 0 and pos[1][1] > 0 and board[pos[0][0]][pos[0][1]-1] == 0 and board[pos[1][0]][pos[1][1]-1] == 0:
            next_pos = ( (pos[0][0], pos[0][1]-1), (pos[1][0], pos[1][1]-1) )
            if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))
            
        # 5. Move Up
        if pos[0][0] > 0 and pos[1][0] > 0 and board[pos[0][0]-1][pos[0][1]] == 0 and board[pos[1][0]-1][pos[1][1]] == 0:
            next_pos = ( (pos[0][0]-1, pos[0][1]), (pos[1][0]-1, pos[1][1]) )
            if not visited.get(next_pos):
                    visited[next_pos] = True
                    queue.append((next_pos, cnt+1))

    return -1

if __name__ == "__main__":
    board = [[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]
    print(solution(board))