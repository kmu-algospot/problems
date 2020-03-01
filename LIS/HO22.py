m = []
n = 0
l = []
def lis(j):
    if m[j+1] != -1:
        return int(m[j+1])
    ret = 0
    for i in range(j+1, int(n)):
        if j == -1 or int(l[j]) < int(l[i]):
            ret = max(ret, lis(i) + 1);
            m[j + 1] = ret
    return ret

c = int(input())
for i in range(c):
    n = input()
    A = input()

    l = A.split()

    m = [-1 for j in range(int(n)+1)]

    print(lis(-1))
