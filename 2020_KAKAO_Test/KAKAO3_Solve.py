# Solve

import bisect

def solution(info, query):
    answer = []

    DP = {} # Memory For Applicant Data
    result_DP = {} # Memory For Result of Query

    # Set Applicant Data
    for data in info:
        a,b,c,d,e = data.split()
        # { Condition : [Scores] }
        condition = a[0]+b[0]+c[0]+d[0]
        if condition not in DP:
            DP[condition] = [int(e)]
        else:
            DP[condition].append(int(e))

    # Sort By Score
    for data in DP.keys():
        DP[data].sort()

    # Processing Query
    for q in query:
        a, _, b, _, c, _, d, e = q.split()
        command = a[0]+b[0]+c[0]+d[0]+e # Query Command : ex) jbjp150
        e = int(e)

        # Command Result is Exist ?
        if command in result_DP:
            answer.append(result_DP[command])
            continue

        # Initialize Data For Result
        result = 0

        cond1 = []
        cond2 = []
        cond3 = []
        cond4 = []

        if a == '-':
            cond1.append('j')
            cond1.append('c')
            cond1.append('p')
        else :
            cond1.append(a[0])

        if b == '-':
            cond2.append('b')
            cond2.append('f')
        else :
            cond2.append(b[0])

        if c == '-':
            cond3.append('j')
            cond3.append('s')
        else :
            cond3.append(c[0])

        if d == '-':
            cond4.append('c')
            cond4.append('p')
        else:
            cond4.append(d[0])

        # Get Result by Condition
        for one in cond1:
            for two in cond2:
                for three in cond3:
                    for four in cond4:
                        if one+two+three+four in DP:
                            idx = bisect.bisect_left(DP[one+two+three+four], e) # Get index of Starting Point by Score
                            result += len(DP[one+two+three+four][idx:]) # Get Result

        result_DP[command] = result # Store Result of Command
        answer.append(result)
    return answer

if __name__ == "__main__":
    info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
    query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]

    print(solution(info, query))