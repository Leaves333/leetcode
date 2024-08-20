class PrefixTreeNode:
    def __init__(self) -> None:
        self.isWord = False
        self.children = {}


class WordDictionary:

    def __init__(self):
        self.root = PrefixTreeNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for char in word:
            if char not in cur.children:
                cur.children[char] = PrefixTreeNode()
            cur = cur.children[char]
        cur.isWord = True

    def search(self, word: str) -> bool:

        def helper(word: str, root: PrefixTreeNode) -> bool:

            if len(word) == 0:
                return root.isWord

            if word[0] == '.':
                ans = False
                for child in root.children.values():
                    ans = ans or helper(word[1:], child)
                    if ans:
                        return ans
                return ans
            else:
                if word[0] not in root.children:
                    return False
                return helper(word[1:], root.children[word[0]])

        return helper(word, self.root)
