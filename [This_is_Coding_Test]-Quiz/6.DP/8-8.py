N, M = map(int, input().split())
coin = []
for i in range(N):
    inp = int(input())
    coin.append(inp)
coin.sort()

# DP Table
dp = [10001] * (M+1)
dp[0] = 0

# Bottom-Up
for money in range(coin[0], M+1):
    for c in coin:
        if money >= c:
            dp[money] = min(dp[money], dp[money-c]+1)
        else:
            break

# Result
if dp[M] == 10001:
    print(-1)
else:
    print(dp[M])