import sys
from copy import deepcopy

C = int(sys.stdin.readline().rstrip())

for i in range(C):
    N, W = map(lambda x: int(x), sys.stdin.readline().rstrip().split())

    items = []
    dp = [{"set": set(), "value": 0} for j in range(W + 1)]
    for j in range(N):
        name, size, value = sys.stdin.readline().rstrip().split()
        size = int(size)
        value = int(value)

        items.append({"name": name, "size": size, "value": value})

    answer = 0
    max_value = 0
    for w in range(W + 1):
        for j in range(N):
            if w >= items[j]["size"]:
                if dp[w]["value"] < dp[w - items[j]["size"]]["value"] + items[j]["value"] and not j in dp[w - items[j]["size"]]["set"]:
                    dp[w]["value"] = dp[w - items[j]["size"]]["value"] + items[j]["value"]
                    dp[w]["set"] = deepcopy(dp[w - items[j]["size"]]["set"])
                    dp[w]["set"].add(j)

                    if max_value < dp[w]["value"]:
                        max_value = dp[w]["value"]
                        answer = w

    print(max_value, len(dp[answer]["set"]))
    for item_idx in dp[answer]["set"]:
        print(items[item_idx]["name"])
