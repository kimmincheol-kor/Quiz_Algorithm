# Example Input
food_times = [3,1,2]
k = 5

# My Variables
seconds = 0
cur_food = 0

# Main Loop : O(K)
while seconds < k+1:
    for i, remain_time in enumerate(food_times):
        if(remain_time > 0):
            cur_food = i
            seconds += 1

            if(seconds == k+1):
                break

            food_times[i] -= 1
