#절박도 누적
def pack(c, i): #capacity , item index
    if i == n:  #총 가방의 물건의 수
        return 0

    if m[c][i] != -1:
        return m[c][i]
    #물건 안담고 다음 item
    ret = pack(c, i + 1)
    # 가방의 capacity보다 작거나 같으면
    if c >= volume[i]:
                 # 안담은 경우, 담은경우 비교해서 절박도가 큰 쪽으로
        ret = max(ret, pack(c - volume[i], i + 1) + need[i])
    m[c][i] = ret
    return ret

#어떤 item을 선택했는지 파악하기 위해서
def reconstruct(c, i):
    if i == n:
        return
    #아이템을 담지않은 경우나 담은경우가 절박도가 동일할때
    #[[-1, -1, -1, 0, 0, 0, -1], [-1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, 5, 5, 0, -1], [-1, -1, -1, -1, -1, -1, -1], [-1, -1, 7, 7, 5, 0, -1], [-1, -1, -1, -1, -1, -1, -1],
    # [-1, 17, 12, 12, 5, 0, -1], [-1, -1, -1, -1, -1, -1, -1], [-1, -1, 12, 12, 5, 0, -1], [-1, -1, -1, -1, -1, -1, -1], [24, 22, 13, 12, 5, 4, -1]]
    if pack(c, i) == pack(c, i + 1):
        reconstruct(c, i + 1)
    else:
        #선택
        picked.append(names[i])
        reconstruct(c - volume[i], i + 1)



for _ in range(int(input())):
    n, c = map(int, input().split())    # 물건의 수 , 용량
    names = []
    volume = []
    need = []
    m = [[-1] * (n + 1) for _ in range(c + 1)]
    for i in range(n):
        name, v, ne = input().split()
        names.append(name)
        volume.append(int(v))
        need.append(int(ne))
    picked = []
    maxVal = pack(c, 0)
    reconstruct(c, 0)
    #print(m)
    #capacity 10일때, [24, 22, 13, 12, 5, 4, -1]
    print(maxVal, len(picked))
    for item in picked:
        print (item)
    
