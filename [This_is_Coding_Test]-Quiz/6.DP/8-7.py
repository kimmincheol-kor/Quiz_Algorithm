N = int(input())

# DP Table
dp = [0] * (N+1)
dp[1] = 1
dp[2] = 3

# Bottom-Up
for i in range(3, N+1):
    dp[i] = (dp[i-2]*2 + dp[i-1]) % 796796

# Result
print(dp[N])