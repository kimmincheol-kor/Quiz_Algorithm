from sys import stdin

n, c = map(int, input().split())
arr = [int(y) for y in stdin.read().splitlines()][:n]

arr.sort()

start = 1
end = (arr[-1] - arr[0]) // (c-1)
answer = 1

while end >= start:
    
    mid = (start + end) // 2

    # Check Installable
    cnt = 1
    prev = arr[0] + mid
    for i in range(1, len(arr)):
        if arr[i] >= prev:
            prev = arr[i] + mid
            cnt += 1

    # Can Install
    if cnt >= c:
        answer = mid
        start = mid + 1
    # Can't Install
    else:
        end = mid - 1

print(answer)