def normalize(num):
    num.append(0)
    for i in range(len(num)-1):
        if ( num[i] < 0 ):
            borrow = (abs(num[i])+9) / 10

            num[i+1]-=borrow
            num[i]+=borrow*10
        else:
            num[i+1]+=num[i]/10
            num[i]%=10
    while(len(num)>1 and num[len(num)-1]==0):
        print(num.pop())

def multiply(a,b):
    c=[0 for i in range(len(a)+len(b))]
    for i in range (len(a)):
        for j in range (len (b)):
            c[i+j]+=a[i]*b[j]
    normalize(c)
    return c

def addTo(a,b,k):
    a += b * (10^k)

def subFrom (a,b):
    if(a>=b):
        a-=b
    else:
        subFrom(b,a)

def karatsuba (a,b):
    an = len(a)
    bn = len(b)

    if(an<bn):
        return karatsuba(b,a)
    if(an==0 or bn==0):
        return 0
    if(an<=50):
        return multiply(a,b)
    #half_a= an/2
    #half_b=bn/2
    half = an/2

    a0=[]
    for i in range(0,half):
        a0.append(a[i])
    a1=[]
    for i in range(half,an):
        a1.append(a[i])
    b0=[]
    for i in range(0,half):
        b0.append(b[i])
    b1=[]
    for i in range(half,bn):
        b1.append(b[i])

    z2=karatsuba(a1,b1)
    z0=karatsuba(a0,b0)

    #addTo(a0,a1,0)      #원래의 곱
    #addTo(b0,b1,0)

    z1=karatsuba(a0,b0)
    subFrom(z1,z0)
    subFrom(z1,z2)

    ret=[]
    addTo(ret,z0,0)
    addTo(ret,z1,half)
    addTo(ret,z2,half+half)

    return ret

a=input()
b=input()
al=[]
bl=[]
for i in range(len(a)):
    al.append(int(a[i]))
for i in range(len(b)):
    bl.append(int(b[i]))

print(karatsuba(al,bl))