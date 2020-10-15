n = int(input())

dp = [0] * (n+5)
for i in range(n):
    t, p = map(int, input().split())
    # Check Today
    if t > 1:
        dp[i+1] = max(dp[i], dp[i+1])
    # Check After (t-1) days
    dp[i+t] = max(dp[i+t], dp[i]+p)

print(max(dp[:n+1]))