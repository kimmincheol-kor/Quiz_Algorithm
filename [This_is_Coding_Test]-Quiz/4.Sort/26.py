import heapq

n = int(input())
heap = []
for _ in range(n):
    heapq.heappush(heap, int(input()))

answer = 0

for _ in range(n-1):
    result = heapq.heappop(heap) + heapq.heappop(heap)
    answer += result
    
    # insert new card-set
    heapq.heappush(heap, result)

print(answer)