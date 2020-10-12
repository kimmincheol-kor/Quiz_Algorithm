n = int(input())
triangle = [-1]

for _ in range(n):
    newArr = list(map(int, input().split()))
    triangle.extend(newArr)

dp = [0] * (len(triangle)+1)
dp[1] = triangle[1]

level = 1
cnt = 0
for i in range(1, len(triangle) - n):

    # left
    if dp[i + level] < dp[i] + triangle[i + level]:
        dp[i + level] = dp[i] + triangle[i + level]

    # Right
    if dp[i + level + 1] < dp[i] + triangle[i + level + 1]:
        dp[i + level + 1] = dp[i] + triangle[i + level + 1]
    
    # Check Level
    cnt += 1
    if cnt == level:
        cnt = 0
        level += 1

print(max(dp[-level:]))