# rotate Matrix - Key
def rotation(key):
    result = []

    for i in range(len(key)):
        new_key = []
        for j in range(len(key)):
            new_key.append(key[len(key)-1-j][i])
        result.append(new_key)

    return result

# check Can Open or Not
def check(key, board, row, col, lock_start, lock_end):
    
    # add Key to Board
    for i in range(row, row+len(key)):
        for j in range(col, col+len(key)):
            board[i][j] += key[i - row][j - col]

    # check Open?
    for a in range(lock_start, lock_end+1):
        for b in range(lock_start, lock_end+1):
            if board[a][b] != 1:
                for i in range(row, row+len(key)):
                    for j in range(col, col+len(key)):
                        board[i][j] -= key[i - row][j - col]

                return False
                
    return True

def solution(key, lock):
    
    # Make Big Board : Lock(Inside Space) + Outside Space
    board = []
    board_length = len(lock) + (2 * len(key)) - 2
    lock_start = len(key) - 1
    lock_end = board_length - len(key)
    for i in range(board_length):
        new_line = []

        if i < lock_start or i > lock_end: # outside
            new_line = [0] * board_length
        else:
            for j in range(board_length):
                if(j < lock_start or j > lock_end): # outside
                    new_line.append(0)
                else: # inside
                    new_line.append(lock[i - lock_start][j - lock_start])

        board.append(new_line)

    # # Travel Board and Check
    # Vertical
    for i in range(board_length - lock_start):
        # Horizon
        for j in range(board_length - lock_start):
            # Rotation
            for _ in range(4):
                if check(key, board, i, j, lock_start, lock_end):
                    return True
                else:
                    key = rotation(key)

    return False

if __name__ == "__main__":
    key = [[0,0,0],[1,0,0],[0,1,1]]
    lock = [[1,1,1],[1,1,0],[1,0,1]]

    print(solution(key, lock))