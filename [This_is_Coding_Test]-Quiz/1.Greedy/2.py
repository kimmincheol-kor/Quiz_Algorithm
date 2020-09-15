import sys

input_data = list(sys.stdin.readline().rstrip())

# String To Int Array
for i, val in enumerate(input_data):
    input_data[i] = int(val)

# Processing
for i in range(0, len(input_data)-1):
    if(input_data[i] > 1 and input_data[i+1] > 1): # Mul
        input_data[i+1] = input_data[i] * input_data[i+1]
    else: # Add
        input_data[i+1] = input_data[i] + input_data[i+1]

# Print Result
print(input_data[-1])