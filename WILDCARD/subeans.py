def wildCard_(pattern, word):
    len_p, len_w = len(pattern), len(word)
    cache = [[-1 for i in range(len_w+1)] for i in range(len_p+1)]

    def match(index_p, index_w):
        if (cache[index_p][index_w] != -1):
            return cache[index_p][index_w]

        if (index_p < len_p and index_w < len_w and (pattern[index_p] == '?' or pattern[index_p] == word[index_w])):
            cache[index_p][index_w] = match(index_p+1, index_w+1)
            return cache[index_p][index_w]  #캐시값 채우고 반환

        if (index_p == len_p):
            return index_w == len_w

        if pattern[index_p] == '*':
            if match(index_p+1, index_w) or (index_w < len_w and match(index_p, index_w+1)):
                # pattern의 '*' 다음글자와 word를 비교한 값 or word의 길이가 끝나지 않았을 때 '*'과 word 글자 비교
                cache[index_p][index_w] = True # 이부분은 따로 값을 저장하지 않고 계산했음을 뜻하는 true로//
                return True

        #cache[index_p][index_w] = False
        else:
            return False


    return match(0, 0)

c= int(input())
for i in range(c):
    pattern = input()
    t = int(input())
    wildcard = []
    for j in range(t):
        s = input()
        #print(wildCard_(pattern,s))
        if(wildCard_(pattern,s)):
            wildcard.append(s)
    wildcard.sort #print(wildcard.sort) 했었는데 sort()기능은 리턴값이 없음
    print(wildcard)
