cache = []
numList = []

def jump(x, y):  # 숫자 격자와 현재 x, y 위치를 입력받음
    if x >= n: return False  # x축 칸을 넘어간 경우
    if y >= n: return False  # y축 칸을 넘어간 경우
    if x == n - 1 and y == n - 1:  # 마지막 칸에 도달
        return True
    result = cache[x][y]  # 메모이제이션
    if result != -1: return result  # 이미 계산했다면
    move = numList[x][y]  # 현재 위치의 칸에 쓰여있는 숫자
    result = jump(x + move, y) or  jump( x, y + move)
    cache[x][y] = result  # 현재 위치 저장
    return result

def init(n) :
    cache = []
    numList = []
    for j in range(n):
        numList.append(list(map(int, input().split()))) # for 문으로 요소 변환해서 리스트화 해주는 걸 map함수를 통해 간략화
    #print(numlist)
    cache = [[-1 for k in range(n)] for l in range(n)] #map과 동일한 모양의 메모이제이션리스트
    return numList,cache

case = int(input())
for i in range(case):
    n = int(input())
    numList,cache=init(n)
    if jump(0, 0):
        print("YES")
    else:
        print("NO")
