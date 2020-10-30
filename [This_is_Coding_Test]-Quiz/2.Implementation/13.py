import itertools as it

def solution(N, M, Board):
    chics = []
    homes = []

    for i in range(N):
        for j in range(N):
            if Board[i][j] == 1:
                homes.append((i,j))
            if Board[i][j] == 2:
                chics.append([(i,j), []])
    
    for ch in chics:
        i = ch[0][0]
        j = ch[0][1]

        for home in homes:
            ch[1].append(abs(i-home[0]) + abs(j-home[1]))

    combi_chic = it.combinations(chics, M)
    answer = 999999

    for chs in combi_chic:
        result = [999999] * len(homes)
        for ch in chs:
            for i in range(len(homes)):
                result[i] = min(result[i], ch[1][i])
        answer = min(answer, sum(result))

    return answer

if __name__ == "__main__":
    N, M = map(int, input().split())
    Board = []

    for i in range(N):
        new = list(map(int, input().split()))
        Board.append(new)

    print(solution(N,M,Board))