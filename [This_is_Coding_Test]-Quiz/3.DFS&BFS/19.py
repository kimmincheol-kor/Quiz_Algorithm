def dfs(curResult, idx):
    global n
    global arr
    global oper
    global maxResult
    global minResult

    if idx == n:
        if curResult > maxResult:
            maxResult = curResult
        if curResult < minResult:
            minResult = curResult
    else:
        for op in range(4):
            if oper[op] > 0:
                newResult = curResult
                
                # Add
                if op == 0:
                    newResult += arr[idx]

                # Sub
                if op == 1:
                    newResult -= arr[idx]

                # Mul
                if op == 2:
                    newResult *= arr[idx]

                # Div
                if op == 3:
                    if newResult < 0:
                        newResult = -(abs(newResult) // arr[idx])
                    else:
                        newResult = newResult // arr[idx]
                    
                oper[op] -= 1
                dfs(newResult, idx+1)
                oper[op] += 1
                
# Main
n = int(input())
arr = list(map(int, input().split()))
oper = list(map(int, input().split()))
maxResult = -1000000001
minResult = 1000000001

dfs(arr[0], 1)

print(maxResult)
print(minResult)