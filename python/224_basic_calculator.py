class Solution:
    def calculate(self, s: str) -> int:

        stack = []
        cur = 0
        number = 0
        sign = 1

        for c in s:
            if c.isdigit():
                number = number * 10 + int(c)
            elif c == '+':
                cur += number * sign
                number = 0
                sign = 1
            elif c == '-':
                cur += number * sign
                number = 0
                sign = -1
            elif c == '(':
                stack.append(cur)
                stack.append(sign)
                sign = 1
                cur = 0
            elif c == ')':
                cur += number * sign
                number = 0
                cur *= stack.pop() # sign
                cur += stack.pop() # number

        if (number != 0):
            cur += number * sign
        return cur
