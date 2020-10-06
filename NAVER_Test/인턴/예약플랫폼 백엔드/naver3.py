# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S, C):
    
    cnt_del = 0
    result = 0
    length = len(S)

    for idx in range(length-1):
        idx += cnt_del
        if idx > length-2:
            break

        if S[idx] == S[idx+1]:
            # Count Same Letter
            cur_cnt = 0
            for i in range(idx, length-1):
                if S[i] == S[i+1]:
                    cur_cnt += 1
                else:
                    break
            
            # Delete Minimum Number
            for i in range(cur_cnt):
                min_idx = C.index(min(C[idx : idx+cur_cnt]))
                result += C[min_idx]
                C[min_idx] = 1001

            cnt_del += cur_cnt
            
    return result

if __name__ == "__main__":
    S = "aaaa"
    C = [3,4,5,6]

    print(solution(S, C))