# User Input
N, K = map(int, input().split())

Items = []

for i in range(N):
    W, V = map(int, input().split())
    Items.append((W, V))

# Memory For Memoization
DP = [[0],[0]]
idx = 0

# Calculate First Item
first_item = Items[0]

for k in range(1, K+1):
    if k < first_item[0]: # Including is Impossible
        DP[idx%2].append(0)
        DP[(idx-1)%2].append(0)
    else: # Possible
        DP[idx%2].append(first_item[1])
        DP[(idx-1)%2].append(first_item[1])
        

if N == 1:
    print(DP[-1][-1])
    exit()

# Calculate Remain Items
for item in Items[1:]:
    idx += 1

    # Each item
    for k in range(1, K+1):
        if k < item[0]: # Including is Impossible
            DP[idx%2][k] = DP[(idx-1)%2][k]
        else: # Possible
            # Include Me vs Exclude Me
            include = item[1] + DP[(idx-1)%2][k-item[0]]
            exclude = DP[(idx-1)%2][k]

            DP[idx%2][k] = max(include, exclude)

print(max(DP[idx%2][-1], DP[idx%2][-1]))
