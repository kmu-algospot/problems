def solution(words):
    answer = 0

    tree = {}
    maxs = [1 for word in range(len(words))]
    lens = [len(word) for word in words]

    num = 0
    for word in words:
        num += 1
        subtree = tree
        count = 0
        for char in word:
            count += 1
            if char in subtree:
                subtree = subtree[char]
                subtree['key'].append(num)
                key_len = len(subtree['key'])
                for key in range(key_len):
                    i = subtree['key'].pop()
                    if maxs[i - 1] <= count:
                        if lens[i - 1] == count:
                            maxs[i - 1] = count
                        else:
                            maxs[i - 1] = count + 1

            else:
                subtree[char] = {'key': [num]}
                subtree = subtree[char]
    answer = sum(maxs)
    return answer
