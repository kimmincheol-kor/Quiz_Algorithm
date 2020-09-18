def solution(N, M, Board):

    chicken = []
    house = {}

    for i in range(0, N):
        for j in range(0, N):
            if Board[i][j] == 1:
                house[(i,j)] = [(-1,-1), 1000]
            if Board[i][j] == 2:
                chicken.append((i,j))

    for _ in range(M):

        list_chicken_distance = []

        for chick in chicken:

            cur_city_distance = 0

            for ho in house.keys():
                distance = abs(chick[0] - ho[0]) + abs(chick[1] - ho[1])
                if distance < house[ho][1]:
                    cur_city_distance += distance
                else:
                    cur_city_distance += house[ho][1]

            list_chicken_distance.append(cur_city_distance)

        selected_idx = list_chicken_distance.index(min(list_chicken_distance))
        selected_chicken = chicken[selected_idx]

        for ho in house.keys():
            distance = abs(selected_chicken[0] - ho[0]) + abs(selected_chicken[1] - ho[1])
            if distance < house[ho][1]:
                house[ho][0] = selected_chicken
                house[ho][1] = distance

    min_city_distance = [x[1] for x in house.values()]
    return sum(min_city_distance)

if __name__ == "__main__":
    N, M = map(int, input().split())
    Board = []

    for i in range(N):
        new = list(map(int, input().split()))
        Board.append(new)

    print(solution(N,M,Board))