class Node(object):
    def __init__(self,key,data=None):
        self.key=key
        self.data=data  # terminal 인 경우 그동안의 글자를 다 넣어주려고 만든 것 # terminal boolean 만 넣으면 단어를 알기위해서는 역추적을 해야되기때문에 그 과정을 줄이려구//
        self.count=0
        self.children={}


class Trie(object):
    def __init__(self):
        self.head=Node(None)

    def insert(self,string):
        current_node = self.head

        for char in string:
            current_node.count+=1
            if char not in current_node.children:
                current_node.children[char] = Node(char)    #노드에 없는 알파벳인 경우 노드생성

            current_node=current_node.children[char]

        current_node.count+=1
        current_node.data=string #마지막 글자인 경우 (for문 진행이 다끝났으므로 )

    def search(self,string):
        current_node=self.head

        for char in string :
            if char in current_node.children:
                current_node = current_node.children[char]
            else:
                return False

        if (current_node.count==1):
            return True
        else:
            return False

def solution(words):
    t = Trie()
    cnt=0
    for word in words:
        t.insert(word)

    for word in words:
        check=False

        for i in range(1,len(word)):
            if t.search(word[:i]):
                cnt+=len(word[:i])
                check=True
                break
        if not check :  #go 같은 경우 
            cnt+=len(word)
            
    return cnt
