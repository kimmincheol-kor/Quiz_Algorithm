def checkCorrect(input_list):
    if len(input_list) == 0:
        return False

    open_l = 0

    for i in input_list:
        if(i == '('):
            open_l += 1
        elif open_l <= 0:
            return False
        else:
            open_l -= 1

    if open_l == 0:
        return True
    else:
        return False

def dfs(w):
    if len(w) == 0:
        return []

    # Seperate w => u, v
    u = []
    v = []
    num_l = 0
    num_r = 0
    for i in w:
        u.extend(i)

        if(i == '('):
            num_l += 1
        else:
            num_r += 1

        if num_l == num_r and u[0] != u[-1] and len(w[num_l+num_r:]) > 0:
            v.extend(w[num_l+num_r:])
            break

    # Recursive Process : v
    new_v = dfs(v)

    # Check Correctness of u
    result = []
    if checkCorrect(u):
        result.extend(u)
        result.extend(new_v)
    else:
        result.extend('(')
        result.extend(new_v)
        result.extend(')')

        for val in u[1:-1]:
            if val == '(':
                result.extend(')')
            else:
                result.extend('(')

    return result

def solution(p):
    p = dfs(p)
    return "".join(p)