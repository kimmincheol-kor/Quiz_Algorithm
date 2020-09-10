# For Min Heap
import heapq
h = []

# Example Input
food_times = [2, 3,1,4]
k = 5

# food times into Min Heap For Get Index
for i, val in enumerate(food_times):
    heapq.heappush(h, (val, i))

# Operation Loop
while True:
    # If end of Loop
    if k == 0:
        break

    # Get Min Index From Min Heap
    min_index = heapq.heappop(h)[1]
    min_value = food_times[min_index]

    # Calculate Cutting Time (Cut Whole Data) = min value * cur food number
    cutting_time = min_value * (len(h)+1)

    print(food_times, "k =", k)
    
    # Can Cutting
    if k >= cutting_time:
        for i in range(len(food_times)):
            if food_times[i] != 0:
                food_times[i] -= min_value

        k -= cutting_time

        # End of Time : Next Food is First Food
        if(k == 0):
            for i in range(len(food_times)):
                if(food_times[i] > 0):
                    print(food_times)
                    print(i+1)
                    break
   
    # Can't Cutting
    # Find Next Food : Can't Cutting
    else:
        while k != 0:
            for i in range(len(food_times)):
                if food_times[i] != 0:
                    if k == 0:
                        print("hi")
                        print(food_times)
                        print(i+1)
                        break
                    else:
                        k-=1