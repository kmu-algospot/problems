def solution(words):
    words.sort()
    answer = 0
    count = 0
    for i in range(len(words) - 1):
        countA = 0
        countB = 0

        for w in range(len(words[i])):
            try:
                if (words[i][w] != words[i + 1][w]) :
                    countA +=1
                    break
            except:
                    countA +=1
                    break                   
            countA+=1



        for w in range(len(words[i])):
            try:
                if (words[i][w] != words[i - 1][w]) :
                    countB +=1
                    break
            except:
                    countB +=1
                    break                   
            countB+=1

        answer+=max(countA, countB)
        
    countA=0
    for w in range(len(words[-1])):
        try:
            if (words[-1][w] != words[-2][w]) :
                countA +=1
                break
        except:
                countA +=1
                break                   
        countA+=1
    answer+=countA
        
    return answer
