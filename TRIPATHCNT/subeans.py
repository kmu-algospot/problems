import sys
#시간초과 에러를 해결하기위한 방법으로 sys.stdin.readline()을 사용

def path(x, y):
    if y == n-1:
        return triangle[y][x]

    if cache[y][x] != -1:
        return cache[y][x]

    ret = max(path(x + 1, y + 1), path(x, y + 1)) + triangle[y][x]
    cache[y][x] = ret

    return ret


def tripathcnt(x, y):
    if y == n-1:
        return 1

    if count[y][x] != -1:
        return count[y][x]

    ret = 0
    if path(x + 1, y + 1) >= path(x, y + 1):    #오른쪽아래
        ret += tripathcnt(x + 1, y + 1)
    if path(x + 1, y + 1) <= path(x, y + 1):    #바로아래
        ret += tripathcnt(x, y + 1)

    count[y][x] = ret

    return ret


read = sys.stdin.readline
for _ in range(int(read().strip())):
    n = int(read().strip())
    triangle = [list(map(int, read().strip().split())) for _ in range(n)]
    print(triangle)
    cache = [[-1]*n for _ in range(n)]
    count = [[-1]*n for _ in range(n)]
    print(tripathcnt(0, 0))
