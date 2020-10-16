n = int(input())
arr = list(map(int, input().split()))

dp = [0] * (n+1)

# LIS : O(N^2)
for i in range(1, n+1):
    if dp[i] == 0:
        dp[i] = 1
    
    for j in range(1, i):
        if arr[j-1] > arr[i-1]:
            dp[i] = max(dp[j]+1, dp[i])

print(n - max(dp))