import bisect

def bs(arr, left, right):
    idxLeft = bisect.bisect_left(arr, left)
    idxRight = bisect.bisect_right(arr, right)
    return idxRight - idxLeft

def solution(words, queries):
    answer = []

    lyric = [[] for _ in range(10001)]
    reverse_lyric = [[] for _ in range(10001)]

    for w in words:
        lyric[len(w)].append(w)
        reverse_lyric[len(w)].append(w[::-1])

    for i in range(10001):
        lyric[i].sort()
        reverse_lyric[i].sort()

    for q in queries:
        if q[0] == '?' and q[-1] == '?':
            answer.append(len(lyric[len(q)]))
        elif q[0] == '?':
            answer.append(bs(reverse_lyric[len(q)], q[::-1].replace('?', 'a'), q[::-1].replace('?', 'z')))
        else:
            answer.append(bs(lyric[len(q)], q.replace('?', 'a'), q.replace('?', 'z')))
    return answer

if __name__ == "__main__":
    words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
    queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
    print(solution(words, queries))