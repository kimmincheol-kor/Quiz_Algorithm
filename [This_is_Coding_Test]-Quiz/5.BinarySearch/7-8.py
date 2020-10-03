def getLength(arr, mid):
    
    result = 0

    for a in arr:
        if a > mid:
            result += a-mid

    return result

n, m = map(int, input().split())
arr = list(map(int, input().split()))

start = 0
end = max(arr)
maxLen = 0

while start <= end:

    mid = (start + end) // 2

    result = getLength(arr, mid)

    if result >= m:
        if mid > maxLen:
            maxLen = mid

        start = mid+1
    else:
        end = mid-1

print(maxLen)