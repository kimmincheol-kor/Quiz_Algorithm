x = int(input())

# DP Table
dp = [0] * (x+1)

# Bottom-Up
for i in range(2, x+1):
    # Do -1
    dp[i] = dp[i-1] + 1
    # / 2
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i//2]+1)
    # / 3
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i//3]+1)
    # / 5
    if i % 5 == 0:
        dp[i] = min(dp[i], dp[i//5]+1)

# Result
print(dp[x])