def solution(n,k):
    if (k<0):
        return 0
    day = 0.75 ** n
    answer = day
    for i in range(k):
        day *= (1/3) * (n-i)/(i+1)
        answer += day
    return answer

cases = int(input())
for i in range(cases):
    height, day = map(int, input().split())
    print(solution(day,2*day-height))
