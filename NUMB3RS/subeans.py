import sys
def search(here, day):
    if day==0:  #0일째인 경우
        if here==p:
            return 1    #두니발이 있는 곳은 교도소 == 확률은 1
        else:
            return 0

    ret = cache[here][day]
    if ret!=-1:
        return ret
    ret=0
    for b in range(n):
        if maps[here][b]==1:
                                 # 옮겨갈 수 있는 마을 경우의 수
            ret+=(search(b,day-1) / (maps[b].count(1)))
    cache[here][day]=ret
    return ret


case = int(sys.stdin.readline())
for i in range(case):
    #마을 수 n_um, 지난일 수 d_ay , 감옥 p_rison
    n,d,p = map(int,sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    t = int(sys.stdin.readline())
    q = list(map(int,sys.stdin.readline().split()))
    cache = [[-1 for k in range(101)] for m in range(51)]   #최대 50개마을 최대 100일

    for j in range(len(q)):
        print(format(round(search(q[j],d),8),"8.8f"),end=" ")
