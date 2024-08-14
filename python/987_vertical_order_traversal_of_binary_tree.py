from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        class QueueNode:
            def __init__(self, node: Optional[TreeNode], depth: int, pos: int):
                self.node = node
                self.depth = depth
                self.pos = pos

        map = dict()
        queue = []
        queue.append(QueueNode(root, 0, 0))

        while (len(queue) > 0):

            top = queue.pop(0)
            if top.node == None:
                continue
            if top.pos not in map:
                map[top.pos] = []

            i = len(map[top.pos])
            while i > 0 and map[top.pos][i - 1].depth == top.depth and map[top.pos][i - 1].node.val > top.node.val:
                i -= 1
            map[top.pos].insert(i, top)

            queue.append(QueueNode(top.node.left, top.depth + 1, top.pos - 1))
            queue.append(QueueNode(top.node.right, top.depth + 1, top.pos + 1))

        ans = []
        for key in sorted(map.keys()):
            ans.append([x.node.val for x in map[key]])
        return ans
