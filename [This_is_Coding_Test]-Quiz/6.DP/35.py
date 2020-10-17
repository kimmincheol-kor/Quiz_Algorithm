n = int(input())
result = [0] * (n+1)
result[1] = 1

# position of 2,3,5
p2 = 1
p3 = 1
p5 = 1

# value of 2,3,5 ( r[i] = q[i] * i )
r2 = 2
r3 = 3
r5 = 5

for i in range(2, n+1):
    result[i] = min(r2,r3,r5)

    if result[i] == r2:
        p2 += 1
        r2 = result[p2] * 2
    if result[i] == r3:
        p3 += 1
        r3 = result[p3] * 3
    if result[i] == r5:
        p5 += 1
        r5 = result[p5] * 5

print(result[n])