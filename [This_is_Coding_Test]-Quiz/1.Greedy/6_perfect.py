import heapq

def solution(food_times, k):
    food_times = [3,1,2]
    k = 5

    # 예외-1
    if sum(food_times) <= k:
        return -1

    # 시간이 작은 음식부터 빼야 한다. -> 우선순위 큐
    q = []
    for i in range(len(food_times)):
        # 음식 시간, 음식 번호
        heapq.heappush(q, (food_times[i], i+1))

    sum_time = 0 # 사용한 시간
    pre_time = 0 # 이전 음식 시간
    num_food = len(food_times) # 현재 남은 음식의 개수

    # 주요 동작
    # (현재 최소 음식 시간 - 이전 음식 시간) * 현재 음식 개수
    while ((q[0][0] - pre_time) * num_food) <= (k - sum_time):
        now = heapq.heappop(q)[0] # now = 최소 음식 시간
        sum_time += (now - pre_time) * num_food
        num_food -= 1
        pre_time = now


    # 남은 음식 중에서 정답을 찾아서 출력
    result = sorted(q, key=lambda x: x[1]) # 음식 번호 기준으로 정렬
    answer = result[(k - sum_time) % num_food][1] # 정답 음식 번호
    return answer
     

    