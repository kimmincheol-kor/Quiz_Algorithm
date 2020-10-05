import sys
input = sys.stdin.readline

n, x = map(int, input().split())
arr = list(map(int, input().split()))

start = 0
end = n-1

result = 0

while start <= end:
    mid = (start + end) // 2

    if arr[mid] < x:
        start = mid + 1
    elif arr[mid] > x:
        end = mid - 1
    else:
        result += 1

        # Left
        for i in range(mid-1, -1, -1):
            if arr[i] != x:
                break
            else:
                result += 1

        # Right
        for i in range(mid+1, n):
            if arr[i] != x:
                break
            else:
                result += 1

        break

if result > 0:
    print(result)
else:
    print(-1)
