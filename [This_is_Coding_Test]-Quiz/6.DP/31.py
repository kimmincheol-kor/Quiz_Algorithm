import copy

t = int(input())
result = []

for _ in range(t):
    n, m = map(int, input().split())
    arr = [-1]
    arr.extend(list(map(int, input().split())))

    dTable = copy.deepcopy(arr)

    ## Left -> Right : Update Max
    # for i in range(1, m): # move col
    #     for j in range(i, n*m, m): # move row
    #         # Right-Up
    #         if j-m > 0:
    #             dTable[(j+1)-m] = max(dTable[(j+1)-m], dTable[j] + arr[(j+1)-m])

    #         # Right
    #         dTable[j+1] = max(dTable[j+1], dTable[j] + arr[j+1])

    #         # Right-Down
    #         if j+m < n*m:
    #             dTable[(j+1)+m] = max(dTable[(j+1)+m], dTable[j] + arr[(j+1)+m])

    # Right -> Left : Find Max
    for i in range(2, m+1): # move col
        for j in range(i, n*m+1, m): # move row
            # Left-Up
            leftup = 0
            if j-m > 0:
                leftup = dTable[j-1-m]

            # Left
            left = dTable[j-1]

            # Left-Down
            leftdown = 0
            if j+m < n*m+1:
                leftdown = dTable[j-1+m]

            dTable[j] = max(leftup, left, leftdown) + arr[j]

    result.append(max(dTable))

print(result)