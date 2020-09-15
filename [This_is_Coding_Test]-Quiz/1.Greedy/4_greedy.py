import sys
import time

N = int(input())
data = list(map(int, sys.stdin.readline().rstrip().split()))

start_time = time.time()
print("time : ", start_time)

data.sort()

target = 1
for num in data: # 새로운 동전 추가
    if target < num: # target 값을 만들 수 없음.
        break
    else: # target 값을 만들 수 있음.
        target += num
    
end_time = time.time()
print("time : ", end_time)

print("time : ", end_time-start_time)