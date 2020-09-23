from itertools import permutations

def solution(n, weak, dist):
    answer = 1000
    weak_length = len(weak)

    # Make Weak Length Double
    for i in range(weak_length):
        weak.append(weak[i]+n)
    
    # All Permutations
    for friends in list(permutations(dist, len(dist))):
        
        # All Start idx in Weak Array
        for start in range(weak_length):
            num_f = 1                           # num of inserted friends
            end_f = weak[start] + friends[0]    # end point of current friend

            # 1. Check Possibility of Solve
            for idx in range(start, start+weak_length):
                if weak[idx] > end_f: # need more friends
                    num_f += 1
                    if num_f > len(dist):
                        break
                    end_f = weak[idx] + friends[num_f-1]
            
            # 2. Success to Solve
            if num_f <= len(dist):
                if answer > num_f:
                    answer = num_f

    # No Answer.
    if answer == 1000:
        return -1
    # Have Answer.
    else:
        return answer


if __name__ == "__main__":
    n = 12
    weak = [1,3,4,9,10]
    dist = [3,5,7]

    print(solution(n, weak, dist))

"""
레스토랑 리모델링
동그란 모양, 외벽의 총 둘레 n 미터

`취약한 지점` 존재 -> 주기적으로 친구들을 보내 점검
빠른 공사 진행을 위해 점검 시간을 1시간으로 제한

각 친구들마다 1시간동안 이동할 수 있는 거리는 다르다.

최소한의 친구들을 투입해 취약 지점을 점검하고, 나머지는 내부 공사

result = 투입해야되는 친구들의 최소 값

북쪽 방향이 0
취약 지점의 위치는 정북 방향에서 부터 시계 방향으로 떨어진 거리

친구들은 시계방향, 반시계방향으로 이동할 수 있다.

n : 식당 외벽의 길이 => [ 0 ~ n-1 ] 의 시계로 생각.
weak : 취약 지점 => 오름차순 정렬되어있다.
dist : 각 친구가 1시간동안 이동할 수 있는 거리
"""
