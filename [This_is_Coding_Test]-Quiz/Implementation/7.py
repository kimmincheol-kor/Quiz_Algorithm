input_data = input()

length = len(input_data)
sum_left = 0
sum_right = 0

# Calculate Sum
for i in range(length):
    if(i < length/2):
        sum_left += int(input_data[i])
    else:
        sum_right += int(input_data[i])

# Result
if sum_left == sum_right:
    print("LUCKY")
else:
    print("READY")