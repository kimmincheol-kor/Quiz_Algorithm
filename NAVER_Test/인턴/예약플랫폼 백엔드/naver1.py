# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S, K):
    today = 0
    week = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]

    for idx, day in enumerate(week):
        if S == day:
            today = idx
            break

    return week[(today+K) % 7]

if __name__ == "__main__":
    S = "Sat"
    K = 23
    print(solution(S,K))