n = int(input())
arr = list(map(int, input().split()))
m = int(input())
find = list(map(int, input().split()))

arr.sort()

for target in find:
    
    finded = 0
    start = 0
    end = len(arr) - 1

    while start <= end:
        mid = (start + end) // 2

        if arr[mid] < target:
            start = mid + 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            finded = 1
            break

    if finded == 0:
        print("0")
    else:
        print("1")