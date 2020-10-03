from functools import cmp_to_key

def compare(stu1, stu2):
    if stu1[1] != stu2[1]:
        return stu2[1] - stu1[1]
    elif stu1[2] != stu2[2] :
        return stu1[2] - stu2[2]
    elif stu1[3] != stu2[3] :
        return stu2[3] - stu1[3]
    elif stu1[0] < stu2[0]:
        return -1
    else:
        return 0

n = int(input())
student = []
for _ in range(n):
    name, korean, english, math = input().split()
    student.append((name, int(korean), int(english), int(math)))

student.sort(key=cmp_to_key(compare))

for i in range(n):
    print(student[i][0])