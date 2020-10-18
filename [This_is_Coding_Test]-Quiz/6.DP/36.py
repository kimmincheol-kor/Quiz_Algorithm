strA = list(input())
strB = list(input())

dp = [[0] * (len(strA)+1) for _ in range(len(strB)+1)]
lcs = []

# DP : LCS Table
for b in range(1, len(strB)+1):
    for a in range(1, len(strA)+1):
        if strA[a-1] == strB[b-1]:
            dp[b][a] = dp[b-1][a-1] + 1
        else:
            dp[b][a] = max(dp[b-1][a], dp[b][a-1])

# TraceBack LCS String
y = len(strB)
x = len(strA)
while dp[y][x] > 0:
    if dp[y-1][x] == dp[y][x]:
        y -= 1
    elif dp[y][x-1] == dp[y][x]:
        x -= 1
    elif dp[y-1][x-1] + 1 == dp[y][x]:
        lcs.append(strB[y-1])
        y -= 1
        x -= 1
lcs.reverse()

# Count Operation
iA = 0
iB = 0
preA = -1
preB = -1
result = 0

# [Not LCS] Between LCS Words
for i in range(len(lcs)):
    idxA = strA[iA:].index(lcs[i]) + iA
    iA = idxA + 1
    idxB = strB[iB:].index(lcs[i]) + iB
    iB = idxB + 1
    
    result += max(idxA-preA-1, idxB-preB-1)

    preA = idxA
    preB = idxB

# [Not LCS] at After Last LCS Word
result += max(len(strA[preA+1:]), len(strB[preB+1:]))

print(result)