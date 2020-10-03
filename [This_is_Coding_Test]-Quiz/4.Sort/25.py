def solution(N, stages):

    answer = []

    rate = [[i+1, 0] for i in range(N+1)]

    # Num of Reached Users
    for s in stages:
        for i in range(s):
            rate[i][1] += 1

    # Calculate Fail Rate = Fail Users / Reached Users
    for i in range(N):
        if rate[i][1] > 0:
            rate[i][1] = (rate[i][1] - rate[i+1][1]) / rate[i][1]
        else:
            break
    del rate[-1]

    # Sort by Fail Rate
    rate.sort(reverse=True, key=lambda rate: rate[1])

    for i in range(N):
        answer.append(rate[i][0])

    return answer

if __name__ == "__main__":
    n = 5
    stages = [2, 1, 2, 6, 2, 4, 3, 3]

    print(solution(n, stages))
