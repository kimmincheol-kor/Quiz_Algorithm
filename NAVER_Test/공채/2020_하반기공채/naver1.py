def solution(m,k):
    msg = list(m)
    keys = list(k)
    idx = 0

    for key in keys:
        print(idx, "key = ", key)
        for i in range(idx, len(msg)):
            print(i)
            if msg[i] == key:
                print("find!")
                idx = i
                del msg[i]
                break

    return "".join(msg)

if __name__ == "__main__":
    m = "acbbcdc"
    k = "abc"

    print(solution(m, k))