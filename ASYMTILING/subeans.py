import sys
MOD=1000000007
cache=[-1 for i in range(100)]

#이게원래 tiling
def tiling(n):
    if (n<=1):
        cache[n]=1
    ret=cache[n]
    if(ret !=-1): return ret
    ret=(tiling(n-1)+tiling(n-2))%MOD
    cache[n]=ret
    return ret

def symetry(n):
    ans=cache[n//2]%MOD
    if(n%2==0):
        ans+=cache[n//2-1]%MOD
    return ans

read=sys.stdin.readline
c=int(read())
for i in range(c):
    n=int(read())
    answer=(tiling(n)-symetry(n))%MOD
    if answer != 1000001:
        print(answer)
    else:
        print(0)
