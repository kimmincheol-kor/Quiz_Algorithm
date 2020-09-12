# Pass to Accuracy
# But
# Fail to Efficiency

import bisect

# Func : Check Applicant Data with Input Data
def check_data(app, a,b,c,d):
    if a != '-' and a != app[0]:
        return False

    if b != '-' and b != app[1]:
        return False

    if c != '-' and c != app[2]:
        return False

    if d != '-' and d != app[3]:
        return False

    return True


def solution(info, query):
    answer = []
    applicants = []

    # Set Applicant Data Tuple-List
    for data in info:
        a,b,c,d,e = data.split()
        applicants.append((a,b,c,d,int(e)))

    # Sort By Score
    applicants.sort(key=lambda x: x[4])

    # Array For Only Score
    origin_arr = [app[4] for app in applicants]
    
    # Processing Query
    for q in query:
        a, _, b, _, c, _, d, e = q.split()
        e = int(e)

        # Num of Applicant who suitable for this Query
        count = 0

        # Get Start Search Point by Score 
        idx = bisect.bisect_left(origin_arr, e)

        # Check Suitable or Not
        for app in applicants[idx:]:
            if check_data(app,a,b,c,d):
                count += 1

        answer.append(count)

    return answer

if __name__ == "__main__":
    info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
    query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]

    print(solution(info, query))