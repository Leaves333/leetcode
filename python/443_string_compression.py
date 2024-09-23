from typing import List

class Solution:
    def compress(self, chars: List[str]) -> int:

        i = 1
        num_repeats = 1
        while i < len(chars):
            print(f"{i}\t{chars}")
            if chars[i] == chars[i - 1]:
                num_repeats += 1
                chars.pop(i)
                i -= 1
            else:
                if num_repeats > 1:
                    digit_chars = [x for x in str(num_repeats)]
                    for j in range(len(digit_chars)):
                        chars.insert(i + j, digit_chars[j])
                    i += 1
                num_repeats = 1
            i += 1

        if num_repeats > 1:
            digit_chars = [x for x in str(num_repeats)]
            chars.extend(digit_chars)

        return len(chars)
