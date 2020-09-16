from collections import deque

# Get Board Size
N = int(input())

# Put Apples on Board
K = int(input())
apples = {}
for _ in range(K):
    row, col = map(int, input().split())
    apples["({},{})".format(col-1, row-1)] = 1

# Move data of Snake
L = int(input())
directions = {}
for _ in range(L):
    X, C = input().split()
    directions[int(X)] = C

# Snake Data
snake = {
    "head": (0,0),
    "body": deque((0,0)),
    "direction": 1,
    "size": 0,
    "age": 0
}

# [ Game Loop ]
while True:
    # Check : Change Direction
    if directions.get(snake["age"]) != None:
        new_direction = directions[snake["age"]]
        if new_direction == 'L': # Left
            snake["direction"] += 3
        elif new_direction == 'D': # Right
            snake["direction"] += 1
        snake["direction"] %= 4

    # Move
    if snake["direction"] == 0: # Up
        snake["head"] = (snake["head"][0], snake["head"][1]-1)
    elif snake["direction"] == 1: # Right
        snake["head"] = (snake["head"][0]+1, snake["head"][1])
    elif snake["direction"] == 2: # Down
        snake["head"] = (snake["head"][0], snake["head"][1]+1)
    elif snake["direction"] == 3: # Left
        snake["head"] = (snake["head"][0]-1, snake["head"][1])

    # Snake's Age (Play Time) += 1
    snake["age"] += 1

    # Check : Out of Board
    if snake["head"][0] < 0 or snake["head"][1] < 0 or snake["head"][0] > N-1 or snake["head"][1] > N-1:
        print("out")
        break

    # Check : Apple
    if apples.get("({},{})".format(snake["head"][0], snake["head"][1])) == 1:
        apples["({},{})".format(snake["head"][0], snake["head"][1])] = 0
        snake["size"] += 1
    else:
        snake["body"].pop()

    # Check : Contact Snake's Body
    if (snake["head"][0], snake["head"][1]) in snake["body"]:
        print("collision")
        break
    
    snake["body"].appendleft((snake["head"][0], snake["head"][1]))

print(snake)