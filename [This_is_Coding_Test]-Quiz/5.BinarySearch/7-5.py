def BinarySearch(arr, start, end, item):

    if start > end:
        return False

    mid = (start + end) // 2

    if arr[mid] == item:
        return True
    elif arr[mid] < item:
        if BinarySearch(arr, mid+1, end, item):
            return True
    else:
        if BinarySearch(arr, start, mid-1, item):
            return True

    return False

n = int(input())
nList = list(map(int, input().split()))
nList.sort()

m = int(input())
mList = list(map(int, input().split()))

for item in mList:
    if BinarySearch(nList, 0, n-1, item):
        print("yes", end=" ")
    else:
        print("no", end=" ")