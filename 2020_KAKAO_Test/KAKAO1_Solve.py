# Solve

def solution(new_id):
    # Step 1.
    new_list = list(new_id.lower())

    # Step 2.
    cnt = 0
    for i in range(len(new_list)):
        i -= cnt
        if new_list[i].isalpha() == False and new_list[i].isdigit() == False and new_list[i] != '-' and new_list[i] != '_' and new_list[i] != '.':
            del new_list[i]
            cnt += 1

        if len(new_list) == 0 or i > len(new_list)-1:
            break

    # Step 3.
    cnt = 0
    for i in range(len(new_list)-1):
        i -= cnt
        if new_list[i] == '.' and new_list[i+1] == '.':
            del new_list[i+1]
            cnt += 1
        
        if len(new_list) == 1 or i > len(new_list)-2:
            break
    
    # Step 4.
    if new_list[0] == '.':
        del new_list[0]
    if len(new_list) > 0 and new_list[-1] == '.':
        del new_list[-1]

    # Step 5.
    if len(new_list) == 0:
        new_list = ['a']
   
    # Step 6.
    if len(new_list) > 15:
        new_list = new_list[:15]
        if new_list[-1] == '.':
            del new_list[-1]

    # Step 7.
    if len(new_list) == 1:
        new_list.append(new_list[0])
        new_list.append(new_list[0])
    elif len(new_list) == 2:
        new_list.append(new_list[1])

    return ''.join(new_list)

if __name__ == "__main__":
    new_id = "...!@BaT#*..y.abcdefghijklm"
    print(solution(new_id))