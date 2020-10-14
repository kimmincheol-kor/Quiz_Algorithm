# SCORE : 55 / 100 (TLE)

def solution(words, queries):
    answer = []

    for q in queries:
        cnt = 0

        if q[0] == '?' and q[-1] == '?':
            for w in words:
                if len(w) == len(q):
                    cnt += 1
        elif q[0] == '?':
            target_idx = 0
            for i in range(len(q)):
                if q[i] != '?':
                    target_idx = i
                    break

            target = q[target_idx:]
            for w in words:
                if w[-len(target):] == target and len(w) == len(q):
                    cnt += 1
        else:
            target_idx = 0
            for i in range(len(q)):
                if q[i] == '?':
                    target_idx = i
                    break

            target = q[:target_idx]
            for w in words:
                if w[:len(target)] == target and len(w) == len(q):
                    cnt += 1

        answer.append(cnt)

    return answer

if __name__ == "__main__":
    words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
    queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
    print(solution(words, queries))