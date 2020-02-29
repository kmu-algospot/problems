def lis(list):
    cache=[0 for j in range(len(list))]
    if ( list[0]<list[1]):
        cache[0]=1
    for i in range(1,len(list)):
        if(int(list[i-1])<int(list[i])):
            cache[i]=cache[i-1]+1
        else:
            cache[i]=1
    return max(cache)


c= int(input())
for i in range(c):
    n = int(input())
    num = input()
    list=num.split()
    print(lis(list))

