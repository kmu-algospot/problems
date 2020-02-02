def hugcount(m,f):
    member,fans=replaceMF(m,f)
    print(member,fans)
    cnt = 0

    m_index=0
    f_index=0
    next=0
    meeting=len(f)-len(m)+1

    while(meeting>0):
        count = [1 for i in range(len(m))]
        for i in range(len(m)):
            if((member[m_index] | fans[f_index])==0):
                count[i]=0
            m_index += 1
            f_index += 1
        print(count)
        if ( 0 not in count ):
            cnt+=1
        m_index=0
        next += 1
        f_index = next
        meeting-=1
    print(cnt)

def replaceMF(m,f):
    mem=[]
    fan=[]
    # 멤버를 2진수로 변환. 남자는 1, 여자는 0
    for i in range(len(m)):
        if (m[i]=="F"):
            mem.append(1)
        else:
            mem.append(0)
    for i in range(len(f)):
        if (f[i]=="F"):
            fan.append(1)
        else:
            fan.append(0)
    return mem,fan

c = int(input())

for i in range(c):
    m = input()
    f = input()
    hugcount(m,f)
