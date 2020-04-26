C = int(input())
N, D, P = (0, 0, 0)


def search(here, days, cache, adj_map):
    if days == 0:
        return 1 if here == P else 0

    if cache[here][days] > -0.5:
        return cache[here][days]

    cache[here][days] = 0

    for there in adj_map[here]["list"]:
        cache[here][days] += search(there, days - 1, cache, adj_map) / adj_map[there]["len"]

    return cache[here][days]


while C:
    C -= 1
    global N, D, P
    N, D, P = map(lambda x: int(x), input().split())

    mapp = []
    adj_map = []
    cache = [[-1 for j in range(D + 1)] for i in range(N)]

    for i in range(N):
        mapp.append(list(map(lambda x: int(x), input().split())))
        adj_map.append({"len": 0, "list": []})
        for j in range(N):
            if mapp[i][j] == 1:
                adj_map[i]["list"].append(j)
                adj_map[i]["len"] += 1

    T = int(input())
    for Q in map(lambda x: int(x), input().split()):
        print(search(Q, D, cache, adj_map),end=" ")
    print()
