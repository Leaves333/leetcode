class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        
        cars = sorted([(position[i], speed[i]) for i in range(len(position))])
        arrival_time = [(target - x[0]) / x[1] for x in cars]
        
        ans = 0
        cur_time = 0
        while len(arrival_time) != 0:
            time = arrival_time.pop()
            if time > cur_time:
                ans += 1
                cur_time = time

        return ans