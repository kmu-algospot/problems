l = []
m = []
n = 0

def dp(y,x):
    if n-1 == y:
        return l[y][x]

    if m[y][x] != -1:
        return m[y][x]

    ret = max(int(dp(y+1,x)), int(dp(y+1, x+1))) + int(l[y][x])
    m[y][x] = ret
    return ret

c = int(input())
for i in range(c):
    n = int(input())
    l = []

    for j in range(n):
        a = input().split()
        l.append(a)

    m = []

    for j in range(int(n) + 1):
        m.append([-1 for k in range(int(n) + 1)])

    print(dp(0,0))
