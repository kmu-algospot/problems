MAX_VAL = 987654321

def parital_sum(seq,length): #배열 다 더하는 함수
    p_sum = [0 for _ in range(length)]
    p_sum[0] = seq[0]
    for index in range(1, length):
        p_sum[index] = p_sum[index-1] + seq[index]
    return p_sum

def partial_sqaured_sum(seq):
        return parital_sum([elem ** 2 for elem in seq],length)    #제곱한거 partial_sum 함수에 넘겨서 제곱의 합 배열 만드는 함수

# 한개의 구간에 대한 답 찾는 함수
def calc_sse(p_sum,p_squared_sum,start, end):
    sum = p_sum[end]
    sq_sum = p_squared_sum[end]
    if start != 0:
        sum = sum - p_sum[start-1] #구간의 합
        sq_sum = sq_sum - p_squared_sum[start-1] #구간의 제곱의 합
    avg = int (float(sum)/(end-start+1) + 0.5)  #반올림한 평균을 구하는 식
    return sq_sum - 2*avg*sum + avg*avg*(end-start+1)   # 어떤수 - 평균 의 제곱을 풀어서 표현한 것


def quantize(start_idx, num_class,length):
    memo = [[-1 for _ in range(10)] for _ in range(length)]
    if start_idx == length:
        return 0
    if num_class == 0:  #묶을 수 없을 때
        return MAX_VAL
    msse = memo[start_idx][num_class - 1]
    if msse != -1:
        return msse

    msse = memo[start_idx][num_class - 1] = MAX_VAL


    for end_idx in range(start_idx, length):
        msse = min(msse, calc_sse(p_sum,p_ssum,start_idx, end_idx) + quantize(end_idx+1, num_class-1,length))
                            # start_idx 부터 end_idx까지 하나의 수로 표현했을 때 최소오류를 반환 + 묶음의 길이를 변화시킬때
        memo[start_idx][num_class-1] = msse
            #메모이제이션은 해당부분집합의 시작 idx 와 몇개의 부분으로 나누었는지를 저장해놓아야 하므로 [idx][몇개부분]
    return msse



test_case = int(input())
length=0
for case in range(test_case):
    inputcount = list(map(int, input().split(' ')))
    (length_seq, num_class) = (inputcount[0], inputcount[1])

    inp=list(map(int,input().split(' ')))
    #1단계
    inp.sort()
    sorted_seq=inp
    length=len(inp)
    #2단계
    p_sum=parital_sum(inp,length)
    p_ssum=partial_sqaured_sum(inp)

    result = quantize(0, num_class,length)
    print(result)
