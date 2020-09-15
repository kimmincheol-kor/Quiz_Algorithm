import sys
from itertools import combinations

import time

N = int(input())
data = list(map(int, sys.stdin.readline().rstrip().split()))

start_time = time.time()
print("time : ", start_time)

combi_sum = []

for i in range(1, N+1):
    result = list(combinations(data, i))
    for a in result:
        combi_sum.append(sum(a))

combi_sum = set(combi_sum)
combi_sum = list(combi_sum)
combi_sum.sort()

prev = combi_sum[0]-1
if(prev != 0):
    print(1)
else:
    for i in combi_sum:
        if(prev + 1 == i):
            prev = i
        else:
            print(prev+1)
            break
    else:
        print(combi_sum[-1]+1)

end_time = time.time()
print("time : ", end_time)

print("time : ", end_time-start_time)