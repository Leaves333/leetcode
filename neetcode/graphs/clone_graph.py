from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:

        # edge cases
        if node is None:
            return None
        if len(node.neighbors) == 0:
            return Node(1)

        # generate graph in adjacency list form
        neighbors: dict[int, list[int]] = {}
        visited: set[int] = set()
        
        def dfs(node: Node):
            if node.val in visited:
                return
            visited.add(node.val)
            for adjacent in node.neighbors:
                if node.val not in neighbors:
                    neighbors[node.val] = []
                neighbors[node.val].append(adjacent.val)
                dfs(adjacent)
        dfs(node)

        # clone the graph
        nodes = [Node(i + 1) for i in range(len(neighbors))]
        for i in neighbors:
            nodes[i - 1].neighbors.extend([nodes[x - 1] for x in neighbors[i]])
        return nodes[0]
