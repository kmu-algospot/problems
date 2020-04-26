C = int(input())

while C:
    C -= 1
    N, D, P = map(lambda x: int(x), input().split())

    mapp = []
    adj_map = []
    towns = [[-1 for j in range(D+1)] for i in range(N)]
    queue = [{"town": P, "level": 1}]

    for i in range(N):
        mapp.append(list(map(lambda x: int(x), input().split())))

        adj_map.append({"len": 0, "list": []})
        for j in range(N):
            if mapp[i][j] == 1:
                adj_map[i]["list"].append(j)
                adj_map[i]["len"] += 1

    while len(queue) > 0:
        top = queue[0]
        queue = queue[1:]
        nowTown = top["town"]
        nowLevel = top["level"]

        for node in adj_map[nowTown]["list"]:
            size = adj_map[nowTown]["len"]
            nowP = towns[nowTown][nowLevel-1]

            if nowLevel == 1:
                nowP = 1

            if towns[node][nowLevel] != -1:
                towns[node][nowLevel] += nowP * 1 / size
            else:
                towns[node][nowLevel] = nowP * 1 / size

            if top["level"] + 1 <= D:
                queue.append({"town": node, "level": top["level"] + 1})
    T = int(input())

    for Q in map(lambda x: int(x), input().split()):
        print(0 if towns[Q][D] == -1 else towns[Q][D], end=" ")
    print()
