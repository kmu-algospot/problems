l=[1,1,]
for i in range(2,101):
    l.append((l[i-2]+l[i-1])%1000000007)

c = int(input())
for i in range(c):
    print(l[int(input())])
