C = int(input())

while C:
    C -= 1
    N, D, P = map(lambda x: int(x), input().split())

    mapp = []
    adj_map = []
    towns = [-1 for i in range(N)]

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

        for node in adj_map[top["town"]]["list"]:
            size = adj_map[top["town"]]["len"]
            nowP = towns[top["town"]]
            if top["level"] == 1:
                nowP = 1
            if towns[node] != -1:
                towns[node] += nowP * 1 / size
            else:
                towns[node] = nowP * 1 / size

            if top["level"] + 1 <= D:
                queue.append({"town": node, "level": top["level"] + 1})
    T = int(input())

    for Q in map(lambda x: int(x), input().split()):
        print(towns[Q], end=" ")
    print()
