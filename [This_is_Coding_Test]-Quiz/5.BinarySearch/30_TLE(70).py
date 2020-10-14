def bs(arr, target):
    begin = 0
    end = len(arr) - 1
    cnt = 0
    while begin <= end:
        mid = (begin + end) // 2
        if arr[mid][:len(target)] > target:
            end = mid - 1
        elif arr[mid][:len(target)] < target:
            begin = mid + 1
        else:
            cnt += 1
            for i in range(mid-1, -1, -1):
                if arr[i][:len(target)] == target:
                    cnt += 1
            for i in range(mid+1, len(arr)):
                if arr[i][:len(target)] == target:
                    cnt += 1
            break
    return cnt

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
            target_idx = 0
            for i in range(len(q)):
                if q[i] != '?':
                    target_idx = i
                    break
            target = q[target_idx:]
            target = target[::-1]

            answer.append(bs(reverse_lyric[len(q)], target))
        else:
            target_idx = 0
            for i in range(len(q)):
                if q[i] == '?':
                    target_idx = i
                    break
            target = q[:target_idx]

            answer.append(bs(lyric[len(q)], target))
    return answer

if __name__ == "__main__":
    words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
    queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
    print(solution(words, queries))