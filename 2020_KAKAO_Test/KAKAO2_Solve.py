# Solve

from itertools import combinations

def solution(orders, course):
    
    answer = []
    new_course = {0:0}

    # Get Data From Orders
    for order in orders:
        for i in course:
            new_combi = list(combinations(list(sorted(list(order))), i))
            for new in new_combi:
                new_c = ''.join(new)
                if new_course.get(new_c, 0) == 0:
                    new_course[new_c] = 1
                else:
                    new_course[new_c] += 1

    # Delete Data : Number of Order < 2
    items = list(new_course.items())
    cnt = 0
    for i in range(len(items)):
        i -= cnt
        if items[i][1] < 2:
            del items[i]
            cnt += 1

    # Determine New Course Menu
    items.sort(key=lambda x: -x[1])
    result = {}
    for item in items:
        if result.get(len(item[0]), 0) <= item[1]:
            result[len(item[0])] = item[1]
            answer.append(item[0])

    return sorted(answer)

if __name__ == "__main__":
    orders = ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]
    course = [2,3,5]

    print(solution(orders, course))