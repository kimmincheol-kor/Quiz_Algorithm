# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N):
    arr = list(str(N))

    # 음수
    if arr[0] == '-':
        for i in range(1, len(arr)):
            if int(arr[i]) > 5:
                arr.insert(i, '5')
                result = int("".join(arr[1:]))
                result *= -1
                break

    # 양수
    else:
        for i in range(len(arr)):
            if int(arr[i]) < 5:
                arr.insert(i, '5')
                result = int("".join(arr))
                break

    return result

if __name__ == "__main__":
    N = -8000
    print(solution(N))