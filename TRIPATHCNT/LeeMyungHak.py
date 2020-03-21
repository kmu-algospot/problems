def solution(n):
    answer = [[int(input()), 1]]
    for i in range(1, n):
        lists = list(map(int, input().split()))
        lists[0] = [lists[0] + answer[0][0], 1]
        lists[-1] = [lists[-1] + answer[-1][0], 1]
        
        for j in range(1, len(lists) - 1):
            if(answer[j][0] == answer[j-1][0]):
                lists[j] = [lists[j] + answer[j][0], answer[j][1] + answer[j-1][1]]
            elif(answer[j][0] > answer[j-1][0]):
                lists[j] = [lists[j] + answer[j][0], answer[j][1]]
            else:
                lists[j] = [lists[j] + answer[j-1][0], answer[j-1][1]]
        answer = lists
    final_answer = 0
    max_num = -1
    for i in range(n):
        if max_num < answer[i][0]:
            final_answer = answer[i][1]
            max_num = answer[i][0]
        elif max_num == answer[i][0]:
            final_answer+=answer[i][1]
    return final_answer
    
if __name__ == '__main__':
    cases = int(input())
    for i in range(cases):
        n = int(input())
        print(solution(n))
