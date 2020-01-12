def quadTree(string , index):
    color = string[index]
    if color == 'w':
        return 'w'
    elif color == 'b':
        return 'b'
    index+=1
    upleft = quadTree(string,index)
    index+=len(upleft)
    upright=quadTree(string,index)
    index+=len(upright)
    downleft = quadTree(string, index)
    index+=len(downleft)
    downright=quadTree(string,index)

    return 'x'+downleft+downright+upleft+upright


n = int(input())
for i in range(n):
    string = input()
    print (quadTree(string,0))