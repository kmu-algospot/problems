def trianglePath(r,c,tr,sum):
    if (r==len(tr)-1):
        return sum + int(tr[r][c])
    ret=cache[r][c]
    if(ret!=-1):
        return ret
    sum+=int(tr[r][c])
    cache[r][c]=sum
    ret = max(trianglePath(r+1,c+1,tr,sum),trianglePath(r+1,c,tr,sum))
    return  ret



c=int(input())
for i in range(c):
    triangle=[]
    li = int(input())
    cache = [[-1 for o in range(li + 1)] for k in range(li + 1)]
    for j in range(li):
        num=input()
        triangle.append(num.split())
    print(trianglePath(0,0,triangle,0))
