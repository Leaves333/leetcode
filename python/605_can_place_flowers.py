class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:

        empty = 0
        for i in range(len(flowerbed)):
            
            if flowerbed[i]:
                continue
            if i < len(flowerbed) - 1 and flowerbed[i + 1]:
                continue
            if i > 0 and flowerbed[i - 1]:
                continue

            flowerbed[i] = 1
            empty += 1

        return empty >= n