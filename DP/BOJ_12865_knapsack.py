N, K = map(int, input().split())

Items = []

for i in range(N):
    W, V = map(int, input().split())
    Items.append((W, V))

DP = []

# Calculate First Item
first_item = Items[0]
first_record = [0]

for k in range(1, K+1):
    if k < first_item[0]:
        first_record.append(0)
    else:
        first_record.append(first_item[1])

DP.append(first_record)

if N == 1:
    print(DP[-1][-1])
    exit()

# Calculate Remain Items
idx = 0
for item in Items[1:]:
    idx += 1
    record = [0]

    # Each item
    for k in range(1, K+1):
        if k < item[0]: # Including is Impossible
            record.append(DP[idx-1][k])
        else: # Possible
            # Include Me vs Exclude Me
            include = item[1] + DP[idx-1][k-item[0]]
            exclude = DP[idx-1][k]

            record.append(max(include, exclude))

    DP.append(record)

print(DP[-1][-1])
