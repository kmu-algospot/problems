def Fence(count):
    FenceList=[]    #주어진 list 에서 큰 값만 list에 추가
    for i in range(len(count)-1):
        if(count[i]<count[i+1]):
            if count[i+1] not in FenceList:
                FenceList.append(count[i+1])
            else:
                continue

    countMax = []   #FenceList 와 곱할 값 countNum에서의 최대값을 넣은 리스트
    countNum = [0 for i in range(len(count))]
    for i in range(len(FenceList)):
        for j in range(len(count)):
            if (FenceList[i]<=count[j]):
                countNum[j]=countNum[j-1]+1
            else:
                countNum[j]=0
        #print(countNum)
        max = countNum[0]   #countNum 에서의 최대값을 countMax 배열에 넣어주는 과정
        for i in range(1, len(countNum)):
            if (countNum[i] > max):
                max = countNum[i]
        countMax.append(max)

    max = countMax[0] * FenceList[0]    #최종 최대값 찾기
    for i in range(1,len(countMax)):
        if(max < countMax[i]*FenceList[i]):
            max=countMax[i]*FenceList[i]
    return max

def makelist(s):
    num=s.split()
    count=[]
    for i in range(len(num)):
        count.append(int(num[i]))
    return count


n=int(input())
while(n):
    c=int(input())      #이렇게하면 이거 받는 의미가 없음 //
    s=input()
    list=makelist(s)
    print(Fence(list))
    n-=1
