# 7-5 => Using Counting Sort

def CountingSort(arr, mem):
    for item in arr:
        mem[item] += 1

n = int(input())
nList = list(map(int, input().split()))
m = int(input())
mList = list(map(int, input().split()))

# Counting Sort
cntMem = [0] * 1000001
CountingSort(nList, cntMem)

for item in mList:
    if cntMem[item] > 0:
        print("yes", end=" ")
    else:
        print("no", end=" ")