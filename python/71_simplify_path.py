class Solution:
    def simplifyPath(self, path: str) -> str:
        
        splits = path.split("/")
        stack = []

        for s in splits:
            if s == "..":
                if len(stack) > 0:
                    stack.pop()
            elif s != "." and s != "":
                stack.append(s)

        if len(stack) == 0:
            return "/"

        ans = ""
        for dir in stack:
            ans += "/" + dir
        return ans
