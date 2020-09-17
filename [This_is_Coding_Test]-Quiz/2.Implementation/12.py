# input
n = 5
build_frame = [[1,0,0,1], [1,1,1,1], [2,1,0,1], [2,2,1,1], [5,0,0,1], [5,1,0,1], [4,2,1,1], [3,2,1,1]]
#build_frame = [[0,0,0,1], [2,0,0,1], [4,0,0,1], [0,1,1,1], [1,1,1,1], [2,1,1,1], [3,1,1,1], [2,0,0,0], [1,1,1,0], [2,2,0,1]]

pillar = {} # pillar
roof = {} # roof

# Operation Loop
for op in build_frame:
    x = op[0]
    y = op[1]
    what = op[2]
    how = op[3]

    # Pillar Operation
    if what == 0:

        # impossible install pillar
        if y >= n or y < 0 or x < 0 or x > n:
            continue

        # Operation : uninstall pillar
        if how == 0:

            # Check Exist Left, Right Roof, Up Pillar
            check_l_roof = roof.get("({},{})".format(x-1, y+1), 0)
            check_ll_roof = roof.get("({},{})".format(x-2, y+1), 0)
            check_r_roof = roof.get("({},{})".format(x, y+1), 0)
            check_rr_roof = roof.get("({},{})".format(x+1, y+1), 0)
            check_u_pillar = pillar.get("({},{})".format(x, y+1), 0)
            check_l_pillar = pillar.get("({},{})".format(x-1, y), 0)
            check_r_pillar = pillar.get("({},{})".format(x+1, y), 0)

            # Check Left Roof can Prevent
            if check_l_roof > 0: # if exist
                if check_r_roof == 0 or check_ll_roof == 0: # not exist roof at least one side
                    if check_l_pillar == 0: # not exist another pillar
                        continue # can't uninstall

            # Check Right Roof can Prevent
            if check_r_roof > 0:
                if check_l_roof == 0 or check_rr_roof == 0:
                    if check_r_pillar == 0:
                        continue

            # Check Up Pillar can Prevent
            if check_u_pillar > 0: # if up pillar exist
                if check_l_roof == 0 and check_r_roof == 0: # not exist roof at both side
                    continue # can't uninstall

            del pillar["({},{})".format(x, y)]

        # End : uninstall pillar

        # Operation : install pillar
        else:

            check_bot_l_roof = roof.get("({},{})".format(x-1, y), 0)
            check_bot_r_roof = roof.get("({},{})".format(x, y), 0)
            check_bot_pillar = pillar.get("({},{})".format(x, y-1), 0)

            if y == 0: # floor
                pillar["({},{})".format(x, y)] = 1
            elif check_bot_l_roof > 0 or check_bot_r_roof > 0:# on the roof
                pillar["({},{})".format(x, y)] = 1
            elif check_bot_pillar > 0: #on the pillar
                pillar["({},{})".format(x, y)] = 1

        # End : install pillar
    # End : Pillar

    # Roof Operation
    else: 
        
        # Out of Range
        if x >= n or x < 0 or y <= 0 or y > n:
            continue

        # uninstall
        if how == 0:
            check_l_roof = roof.get("({},{})".format(x-1, y), 0)
            check_r_roof = roof.get("({},{})".format(x+1, y), 0)
            check_top_l_pillar = pillar.get("({},{})".format(x, y), 0)
            check_top_r_pillar = pillar.get("({},{})".format(x+1, y), 0)
            check_bot_l_pillar = pillar.get("({},{})".format(x, y-1), 0)
            check_bot_l_l_pillar = pillar.get("({},{})".format(x-1, y-1), 0)
            check_bot_r_pillar = pillar.get("({},{})".format(x+1, y-1), 0)
            check_bot_r_r_pillar = pillar.get("({},{})".format(x+2, y-1), 0)

            # 1. left roof
            if check_l_roof > 0:
                if check_bot_l_pillar == 0 and check_bot_l_l_pillar == 0:
                    continue

            # 2. right roof
            if check_r_roof > 0:
                if check_bot_r_pillar == 0 and check_bot_r_r_pillar == 0:
                    continue

            # 3. top left pillar
            if check_top_l_pillar > 0:
                if check_bot_l_pillar == 0 and check_l_roof == 0:
                    continue

            # 4. top right pillar
            if check_top_r_pillar > 0:
                if check_bot_r_pillar == 0 and check_r_roof == 0:
                    continue

            del roof["({},{})".format(x, y)]

    
        # install
        else:
            check_l_roof = roof.get("({},{})".format(x-1, y), 0)
            check_r_roof = roof.get("({},{})".format(x+1, y), 0)
            check_l_pillar = pillar.get("({},{})".format(x, y-1), 0)
            check_r_pillar = pillar.get("({},{})".format(x+1, y-1), 0)

            if check_l_roof > 0 and check_r_roof > 0: # Exist roof at both side
                roof["({},{})".format(x, y)] = 1
            
            if check_l_pillar > 0 or check_r_pillar > 0: # Exist pillar at least one side
                roof["({},{})".format(x, y)] = 1
            
    # End : Roof

# result array
result = []

# get pillar data
for pil_key in list(pillar.keys()):
    val1 = int(pil_key[1])
    val2 = int(pil_key[3])
    result.append(list((val1, val2, 0)))

# get roof data
for roof_key in list(roof.keys()):
    val1 = int(roof_key[1])
    val2 = int(roof_key[3])
    result.append(list((val1, val2, 1)))

# Print Result
result.sort()
print(result)