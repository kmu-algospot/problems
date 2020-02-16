
def wildCard_(pattern, word):
    len_p, len_w = len(pattern), len(word)
    nth = 0
    # 확인할 문자의 위치 변수. 0으로 초기화
    while ( nth < len_p and nth < len_w and (pattern[nth] == '?' or pattern[nth] == word[nth])):
        nth += 1

    if len_p == nth:
        return nth == len_w

    if pattern[nth] == '*':
        skip = 0
        while (skip + nth <= len_w): # "*" 의 pattern 일때 빈 문자열인경우도 고려
            #"*"의 다음부터 자른 패턴과, 그 시점 이후로의 word
            if (wildCard_(pattern[nth+1:], word[skip+nth:])):
                #패턴의 남은 문자열과 word의 나머지 부분이 맞는지 확인하려고 재귀사용
                return True
            skip+=1


c= int(input())
for i in range(c):
    pattern = input()
    t = int(input())
    wildcard = []
    for j in range(t):
        s = input()
        if(wildCard_(pattern,s)):
            wildcard.append(s)
    wildcard.sort #print(wildcard.sort) 했었는데 sort()기능은 리턴값이 없음
    print(wildcard)

