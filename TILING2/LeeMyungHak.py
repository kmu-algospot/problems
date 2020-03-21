# import numpy as np
# import math

# def fast_fibo(n):
#     fibo_base = []
#     fibo_base.append(np.array([[1,1],[1,0]]))
    
#     for i in range(int(math.log2(n))+1):
#         fibo_base.append(fibo_base[i].dot(fibo_base[i]))
#     answer = 0
#     while n >0:
#         idx = int(math.log2(n))
#         answer += fibo_base[idx][0][0]
#         n-= 2**idx
#     return answer

def fibo(n):
    a= 1
    b = 2
    answer = n
    for i in range(n-2):
        answer = a+b
        a= b
        b= answer
    return answer

cases = int(input())
for i in range(cases):
    n = int(input())
    print(fibo(n)%1000000007)
