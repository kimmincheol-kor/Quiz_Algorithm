n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))

answer = 0
arr.sort(reverse=True)

while True:
    result = arr.pop() + arr.pop()
    answer += result
    
    # insert new card-set
    for i in range(1, len(arr)+1):
        idx = len(arr) - i
        if arr[idx] >= result:
            arr.insert(idx+1, result)
            break

    if len(arr) < 2:
        break

print(answer)