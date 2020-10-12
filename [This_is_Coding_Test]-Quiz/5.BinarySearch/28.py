n = int(input())
arr = list(map(int, input().split()))

start = 0
end = len(arr) - 1

while start <= end:
    mid = (start + end) // 2

    target = arr[mid]

    if target == mid:
        print(target)
        exit()
    elif target < mid:
        start = mid + 1
    else:
        end = mid - 1

print(-1)