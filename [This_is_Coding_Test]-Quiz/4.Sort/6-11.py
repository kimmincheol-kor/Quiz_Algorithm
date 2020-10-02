n = int(input())
arr = []

for _ in range(n):
    student = input().split()
    arr.append((student[0], int(student[1])))

# Sort by Value of arr[1]
arr.sort(key=lambda arr: arr[1])

for student in arr:
    print(student[0])