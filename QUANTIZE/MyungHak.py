# # import numpy as np
# # time over 2
# INF = 1000000001
# cache = [[INF for i in range(11)] for j in range(101)]
# arr = []

# def MSE(start, end):
# #    return sum((int(round(np.mean(arr))) - np.array(arr))**2)
#     mean = int(round(sum(arr[start:end])/(end-start)))
#     return sum((i - mean)**2 for i in arr[start:end])
    
# def quantize(start, s):
#     length_arr = len(arr)
#     if len(set(arr[start:]))<= s:
#         return 0
#     if s == 1:
#         return MSE(start, len(arr))
#     elif cache[length_arr][s] != INF:
#         return cache[length_arr][s]
#     for slicer in range(start + 1,len(arr) + 1):
#         cache[start][s] = min(cache[start][s], (MSE(start, slicer) + quantize(int(slicer), s-1)))

#     return cache[start][s]

# if __name__ == '__main__':
#     cases = int(input())
#     for i in range(cases):
#         length, s = list(map(int, input().split()))
#         arr = list(map(int, input().split()))
#         arr.sort()
#         cache = [[INF for i in range(s+1)] for j in range(length+1)]
#         print(quantize(0, s))


#위 알고리즘에서 MSE 구하는방법 바꿈
# import numpy as np
# time over 3
import sys
INF = 1000000001
def solution(arr,length, s):
    def MSE(start, end):
        p_sum = cum_sum[end] - (cum_sum[start-1] if start != 0 else 0)
        p_sq_sum = cum_sq_sum[end] - (cum_sq_sum[start-1] if start != 0 else 0)
        mean = round(p_sum / (end - start + 1))

        ret = p_sq_sum + mean*(-2*p_sum + mean*(end-start+1)) 
        return ret

    def quantize(start, s):
        if (length - start)<= s:
            return 0
        elif s == 1:
            return MSE(start,length-1)
        elif cache[start][s] != INF:
            return cache[start][s]
        
        for slicer in range(start + 1,length + 1):
            cache[start][s] = min(cache[start][s], (MSE(start, slicer - 1) + quantize(slicer, s-1)))
        return cache[start][s]
    
    arr.sort()
    cum_sum = [0 for _ in range(length)]
    cum_sq_sum = [0 for _ in range(length)]

    cum_sum[0] = arr[0]
    cum_sq_sum[0] = arr[0]**2
    for i in range(1, length):
        cum_sum[i] = cum_sum[i-1] + arr[i]
        cum_sq_sum[i] = cum_sq_sum[i-1] + arr[i]**2  
    cache = [[INF for _ in range(s+1)] for _ in range(length+1)]
    return quantize(0,s)



if __name__ == '__main__':

    cases = int(sys.stdin.readline())
    for i in range(cases):
        length, s = map(int,sys.stdin.readline().split())
        arr = list(map(int,sys.stdin.readline().split()))
        print(solution(arr, length, s))
