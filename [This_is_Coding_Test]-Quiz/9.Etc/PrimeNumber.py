# Pirme Nuber : 2보다 큰 자연수 중에서 1과 자기 자신을 제외한 자연수로는 나누어 떨어지지 않는 자연수.
#                   => 약수가 오직 [1, 자기 자신]
#
# 특정 수가 소수인지 아닌지 판별 : 소수의 판별

import math

def isPrime(x):
    for target in range(2, x): # 2 , 3 ,,, x-1
        if x % target == 0:
            return False
    return True # O (X)

def advanced_isPrime(x):
    sqrt = int(math.sqrt(x)) + 1
    for target in range(2, sqrt):
        if x % target == 0:
            return False
    return True # O(X ^ 1/2)

# Sieve of Eratosthenes : 범위 내의 여러 개의 소수를 찾아야 할때
# (에라토스테네스의 체)

def eratos(n):
    sqrt = int(math.sqrt(n)) + 1
    arr = [True] * (n+1)
    arr[0] = False
    arr[1] = False

    for i in range(2, sqrt):
        if arr[i] == True:
            for j in range(2, n//i+1):
                arr[i*j] = False

    print(arr.count(True))