def solution(a,b):
    global A
    global B
    global cache
    if a >= len(A) or b >= len(B):
        return -1

    ret = 2
    
    if(a == -1):
        numA = -2**32-1
    else:
        numA = A[a]
    if(b == -1):
        numB = -2**32-1
    else:
        numB = B[b]
    
    maxElement = max(numA, numB)
    
    for i in range(a+1, len(A)):
#        print(i)
        if maxElement < A[i]:
            ret = max(ret, solution(i,b)+ 1)

    for i in range(b+1, len(B)):
        if maxElement < B[i]:
            ret = max(ret, solution(a,i)+ 1)
    return ret
        
    
N = input()
for i in range (int(N)):
    x, y = map(int, input().split())
    cache = [[-1 for k in range(x)] for j in range(y)]
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    print(solution(-1, -1) - 2)
    
