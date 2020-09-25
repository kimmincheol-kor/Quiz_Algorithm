N = int(input())
K = list(map(int, input().split()))

# DP Table
dp = [0] * N
dp[0] = K[0]
dp[1] = max(dp[0], K[1])

# Bottom-Up
for i in range(2, N):
    # include myself
    inc = dp[i-2] + K[i]
    # exclude mysel
    exc = dp[i-1]

    dp[i] = max(inc, exc)

print(dp[N-1])
