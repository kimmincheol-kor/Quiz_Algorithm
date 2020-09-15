import sys

N, M = map(int, input().split())
weights = list(map(int, sys.stdin.readline().rstrip().split()))

print(weights)

result = 0
cnt = 0

for i in weights:
    cnt += 1
    for j in weights[cnt:N]:
        if(i != j):
            result+=1

print(result)