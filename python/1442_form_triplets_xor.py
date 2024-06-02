class Solution:
    def countTriplets(self, arr: List[int]) -> int:

        psum = [0]
        for i in range(len(arr)):
            psum.append(psum[-1] ^ arr[i])

        ans = 0
        for i in range(len(psum)):
            for j in range(i + 2, len(psum)):
                if psum[i] ^ psum[j] == 0:
                    ans += j - i - 1
        
        return ans