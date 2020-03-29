N, S = map(int, input().split())
A = list(map(int, input().split()))

#print(A)
start_idx=0
len=0
min=1000000
sum=0
cnt=0
while(start_idx<N):
    for j in range(start_idx,N):
        if (sum >= S):
            #print(cnt)
            len=cnt
            sum=0
            cnt=0
            start_idx+=1
            break
        else:
            #print(sum)
            sum += A[j]
            cnt+=1

    if (min>len):
        min=len


print(min)
