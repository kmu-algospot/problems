def poly(n, first):    # n = 폴리노미오 만들 정사각형 개수 , 한 줄에 놓을 정사각형 수 
    if first == n:
        return 1
    if board[n][first] != -1:
        return board[n][first]
    ret = 0
    for o in range(1, n-first + 1): # 그 다음 줄에 올 수 있는 정사각형 수 : 총 정사각형개수에서 한줄에 놓일 정사각형의 수를 뺀 나머지 정사각형 수만큼 
        #위치선정의 방법의 수는 ( 다음 줄의 정사각형개수 + 한줄에 놓일 정사각형개수 - 1 ) 
        # * 나머지층들을 다시 poly 함수로  
        ret += (o + first - 1) * poly(n-first, o)
        ret %= 10000000
    board[n][first] = ret
    return ret


board = [[-1 for j in range(101)] for k in range(101)]
case = int(input())
for i in range(case):
    num = int(input())
    result = 0
    for first in range(1, num + 1):
        result += poly(num, first)
        result %= 10000000
    print(result)
