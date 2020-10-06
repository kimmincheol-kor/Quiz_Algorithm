def printMap(bMap):

    height = len(bMap)

    for h in range(height):
        print(bMap[h])

def solution(blocks):
    answer = []

    height = len(blocks)
    bMap = []

    for i in range(height):
        line = []
        for j in range(i+1):
            if blocks[i][0] == j:
                line.append(blocks[i][1])
            else:
                line.append('X')
        bMap.append(line)

    for h in range(1, height):
        
        while bMap[h].count('X') > 0:
            for i in range(h+1):
                if bMap[h][i] != 'X':
                    print(h, i)
                    if i > 0 and bMap[h][i-1] == 'X':
                        bMap[h][i-1] = bMap[h-1][i-1] - bMap[h][i]
                        printMap(bMap)
                    if i < h and bMap[h][i+1] == 'X':
                        bMap[h][i+1] = bMap[h-1][i] - bMap[h][i]
                        printMap(bMap)

    for h in range(height):
        for i in range(h+1):
            answer.append(bMap[h][i])

    return answer

if __name__ == "__main__":
    blocks = [[0, 50], [0, 22], [2, 10], [1, 4], [4, -13]]

    print(solution(blocks))