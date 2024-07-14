class Solution:
    def isValid(self, s: str) -> bool:
        
        stack = []
        closed_brackets = ')]}'
        open_brackets = '([{'

        for char in s:
            idx = closed_brackets.find(char)

            if idx != -1:   
                if len(stack) == 0:
                    return False

                top_idx = open_brackets.find(stack[-1])
                if top_idx != idx:
                    return False
                stack.pop()
                
            else:
                stack.append(char)
        
        return len(stack) == 0