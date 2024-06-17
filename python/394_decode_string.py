class Solution(object):
    def decodeString(self, s):

        idx = 0
        stack = [[0, '']] # multiplier, string

        while idx < len(s):

            if s[idx].isalpha():
                stack[-1][1] += s[idx]
                idx += 1

            elif s[idx].isdigit():
                left = s.find('[', idx)
                mult = int(s[idx:left])
                idx = left + 1
                stack.append([mult, ''])

            else:
                stack[-2][1] += stack[-1][0] * stack[-1][1]
                stack.pop()
                idx += 1

        return stack[0][1]