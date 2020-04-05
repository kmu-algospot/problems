import math

def snail(climbed, days):
    if 2*days < climbed:
        return 0
    elif climbed <= days:
        return 1
    prob = 0
    for i in range(climbed - days, days + 1): 
        prob += pow(0.75, i) * pow(0.25, days - i) * (math.factorial(days) / (math.factorial(i) * math.factorial(days - i)))
    return prob

for _ in range(int(input())):
    m, n = map(int, input().split())
    result = snail(m, n)
    print('%.10f' %result)
