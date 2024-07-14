import math

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        stack = []

        for x in tokens:
            if x in '+-*/':
                second = stack.pop()
                first = stack.pop()
                if x == '+':
                    stack.append(first + second)
                elif x == '-':
                    stack.append(first - second)
                elif x == '*':
                    stack.append(first * second)
                else:
                    tmp = first / second
                    if tmp < 0:
                        stack.append(math.ceil(tmp))
                    else:
                        stack.append(math.floor(tmp))
            else:
                stack.append(int(x))

        return stack[0]