n = int(input())
arr = list(map(int, input().split()))

arr.sort()

if len(arr) % 2 == 0:
    print(arr[len(arr)//2 - 1])
else:
    print(arr[len(arr)//2])