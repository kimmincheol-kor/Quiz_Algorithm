import bisect

n = int(input())
arr = list(map(int, input().split()))
arr.reverse()

result = [arr[0]]

# LIS : O(N * log N) - result
for a in arr[1:]:
    if result[-1] < a:
        result.append(a)
    else:
        idx = bisect.bisect_left(result, a)
        result[idx] = a

print(n - len(result))