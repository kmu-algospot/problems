mm = []

def jlis(la, lb, a, b):

    if mm[a+1][b+1] != -1:
        return mm[a+1][b+1]

    ret = 0

    ma = int(la[a])
    mb = int(lb[b])

    if a == -1:
        ma = -2147483649
    if b == -1:
        mb = -2147483649

    mx = max(ma, mb)

    for i in range(a+1, len(la)):
        if mx < int(la[i]):
            ret = max(ret, jlis(la, lb, i, b)+1)
            mm[a+ 1][b + 1] = ret

    for i in range(b+1, len(lb)):
        if mx < int(lb[i]):
            ret = max(ret, jlis(la, lb, a, i)+1)
            mm[a+1][b+1] = ret

    return ret


# def lis(l, j, m):
#     s = []
#     prei = l[j-1]
#     s.append(prei)
#     for i in range(j, len(l)):
#         if int(l[i]) <= int(prei):
#             print(lis(l, i+1, m))
#         else:
#             s.append(l[i])
#             prei = l[i]
#     if s not in m:
#         m.append(s)
#     return m


c = int(input())
for i in range(c):
    n, m = input().split()
    A = input()
    B = input()
    num = 0
    answer = 0

    listA = A.split()
    listB = B.split()
    mm = []

    for j in range(int(n)+1):
        mm.append([-1 for j in range(int(m)+1)])

    # for i in listA:
    #     if i <= prei:
    #         numA += 1
    #         lisA.append([i])
    #     else:
    #         lisA[numA].append(i)
    #     prei = i
    #
    # for j in listB:
    #     if j <= prej:
    #         numB += 1
    #         lisB.append([j])
    #     else:
    #         lisB[numB].append(j)
    #     prej = j
    #
    #
    # lisA.sort(key=len, reverse=True)
    # lisB.sort(key=len, reverse=True)
    # sw = 0
    # for A in lisA:
    #     for B in lisB:
    #         if len(A) + len(B) < answer:
    #             sw = 1
    #             break
    #         num = 0
    #         for i in A:
    #             if i in B:
    #                 num += 1
    #
    #         if len(A)+len(B)-num > answer:
    #             answer = len(A)+len(B)-num
    #     if sw == 1:
    #         break
    answer = jlis(listA, listB, -1, -1)
    # if answer == 0:
    #     answer = 1
    #     print(answer)
    # else:
    print(answer)
