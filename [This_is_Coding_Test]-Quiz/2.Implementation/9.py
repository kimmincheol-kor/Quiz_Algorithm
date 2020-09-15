def solution(s):
    # Get Input
    inp = s

    length = len(inp) # length of Origin
    max_compress = 0 # answer

    # < Operation Loop >
    # => All Unit
    for unit in range(1, length//2+1): # 5 => 1,2 | 10 => 1,2,3,4,5
        
        point = 0 # Start Point of Base SubString
        total_compress = 0 # Count Number of Total Compress in Each Unit

        # => Each Unit
        while True:

            # Start Point of First Target Substring
            if point + unit >= length-1:
                break

            # Base SubString
            std = inp[point:point+unit]
    
            # Count Number of Compress
            cnt_compress = 0

            # => Each SubString
            # Compare Each SubString with Base SubString
            for i in range(point+unit, length, unit):

                point = i # Set Next Point
                
                # Different => Change Base
                if(std != inp[i:i+unit]):
                    break
                # Same => Count Compress
                else:
                    cnt_compress += 1

            # Add Count to Total Compress of This Unit
            if cnt_compress > 0:
                total_compress += cnt_compress * unit - 1

                if cnt_compress >= 9:
                    total_compress -= 1
                if cnt_compress >= 99:
                    total_compress -= 1
                if cnt_compress >= 999:
                    total_compress -= 1

        # Check Max or Not
        if total_compress > max_compress:
            max_compress = total_compress

    # Result
    return length - max_compress

if __name__ == "__main__":
    s = input()
    print(solution(s))