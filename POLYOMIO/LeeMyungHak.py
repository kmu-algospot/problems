cache = [[-1 for i in range(100)] for j in range(100)]
def solution(n):
    def poly(top, n):
        if n == top: 
            return 1
        answer = cache[n][top]
        if answer != -1:
            return answer
            
        answer = 0
        ret = cache
        for Next in range(top,n): # 맨 위에 top개가 있을 때 부터 n개가 있을 때 까지
            answer += (Next * poly(Next - top + 1, n-top)) % 10000000
        cache[n][top] = answer
        return answer

    answer = 0
    for top in range(1, n+1): # 맨 위에 1개가 있을 때 부터 n개가 있을 때 까지
        answer += poly(top,n)
        answer%=10000000
    return answer


cases = int(input())
for i in range(cases):
    n = int(input())
    print(solution(n))
