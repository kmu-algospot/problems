def matMul(mat1, mat2):
    answer = []
    for i in range(len(mat1)):
        T = []
        for j in range(len(mat2)):
            n = 0
            for k in range (len(mat2)):
                n += (mat1[i][k] * mat2[k][j])
            T.append(n)
        answer.append(T)
    return answer

def Transpose(mat):
    answer = []
    for i in range(len(mat)):
        T = []
        for j in range(len(mat[0])):
            T.append(mat[j][i])
        answer.append(T)
    return answer

def solution(N, D, P):
    base_arr = []
#     base_arr = [[0, 1, 1, 1, 0, 0, 0, 0,3],
#                 [1, 0, 0, 1, 0, 0, 0, 0,2],
#                 [1, 0, 0, 1, 0, 0, 0, 0,2],
#                 [1, 1, 1, 0, 1, 1, 0, 0,5],
#                 [0, 0, 0, 1, 0, 0, 1, 1,3],
#                 [0, 0, 0, 1, 0, 0, 0, 1,2],
#                 [0, 0, 0, 0, 1, 0, 0, 0,1],
#                 [0, 0, 0, 0, 1, 1, 0, 0,2]]
    for i in range(N):
        T_arr = list(map(int, input().split(" ")))
        S = sum(T_arr)
        T_arr. append(S)
        base_arr.append(T_arr)

    probability_mat = []
    for i in range(N):
        T_arr = []
        for j in range(N):
            if base_arr[i][j] ==1:
                T_arr.append(1/base_arr[j][N])
            else:
                T_arr.append(0)
        probability_mat.append(T_arr)
    
    answer_vec = []
    for i in range(N):
        if i == P:
            answer_vec.append(1)
        else:
            answer_vec.append(0)
    
    
    probability_mat = Transpose(probability_mat)
    
    for i in range(D):
        answer_vec = matMul([answer_vec], probability_mat)[0]

    
    T = int(input())
    arr = list(map(int, input().split(" ")))
    answer = []
    for i in arr:
        answer.append(answer_vec[i])
    return answer
    
cases = int(input())
for i in range(cases):
    N, D, P = list(map(int, input().split(" ")))   #마을수, 지난 일수, 교도소

    arr = solution(N, D, P)
    for n in arr:
        print(n)
