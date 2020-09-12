# User Input
N, K = map(int, input().split())

DP = {0:0}

for i in range(N):
    new_set = []
    w,v = map(int, input().split())

    for ex_w, ex_v in DP.items():
        if ex_w + w <= K:
            new_set.append((ex_w+w, ex_v+v))

    for new_w, new_v in new_set:
        if new_v > DP.get(new_w, 0):
            DP[new_w] = new_v

print(max(list(DP.values())))
