class PrefixTreeNode:
    def __init__(self, isWord: bool) -> None:
        self.isWord = isWord
        self.children = {}

class PrefixTree:

    def __init__(self):
        self.root = PrefixTreeNode(False)

    def insert(self, word: str) -> None:

        i = 0
        cur = self.root

        # traverse down the tree
        while i < len(word):
            if word[i] not in cur.children:
                cur.children[word[i]] = PrefixTreeNode(False)
            cur = cur.children[word[i]]
            i += 1

        cur.isWord = True

    def search(self, word: str) -> bool:

        i = 0
        cur = self.root

        while i < len(word):
            if word[i] not in cur.children:
                return False
            cur = cur.children[word[i]]
            i += 1

        return cur.isWord

    def startsWith(self, prefix: str) -> bool:

        i = 0
        cur = self.root

        while i < len(prefix):
            if prefix[i] not in cur.children:
                return False
            cur = cur.children[prefix[i]]
            i += 1
        
        return True
