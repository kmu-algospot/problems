N, S = map(int, input().split())
A = list(map(int, input().split()))

# 먼저 0~n까지의 합을 구해줌
sum= [0] * (N + 1)
for i in range(1, N + 1):
    sum[i] = sum[i - 1] + A[i - 1]


answer = 1000001
start = 0
end = 1

while (start != N):
    if sum[end] - sum[start] >= S:
        answer=min(answer,end-start)
        start += 1
    else:
        if end != N:
            end += 1
        else:
            start += 1


############################이거없으면 틀림
if answer != 1000001:
    print(answer)
else:
    print(0)
