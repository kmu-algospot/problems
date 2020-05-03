import sys

def main() :

    test_case = int(sys.stdin.readline())

    for case in range(test_case) :
        product_num, max_weight = map(int, sys.stdin.readline().rstrip().split(" "))
        product = []                #[물건이름, 부피, 절박도]
        cache = [[0,[]] for i in range(max_weight+1)]        #[[총 절박도, [물건목록 리스트]]

        for i in range(product_num) :
            product.append(sys.stdin.readline().rstrip().split(" "))
            product[i][1] = int(product[i][1])
            product[i][2] = int(product[i][2])

        answer = 0
        max = 0
        for w in range(max_weight+1):
            for p in product:
                if p[1] <= w :
                    if (cache[w][0] < cache[w-p[1]][0] + p[2]) and not p in cache[w-p[1]][1] :
                        cache[w][0] = cache[w-p[1]][0] + p[2]
                        cache[w][1].clear()
                        for i in range(len(cache[w-p[1]][1])):
                            cache[w][1].append(cache[w-p[1]][1][i])
                        cache[w][1].append(p)

                        if max < cache[w][0]:
                            max = cache[w][0]
                            answer = w

        print(max, len(cache[answer][1]))
        for p in cache[answer][1]:
            print(p[0])
main()
