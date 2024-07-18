class Solution {

    public int minEatingSpeed(int[] piles, int h) {
        
        int low = 0, high = 1000000000;
        while (low < high) {
            int mid = (low + high) / 2;
            if (solve(piles, h, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return high;

    }

    private boolean solve(int[] piles, int h, int speed) {
        int time = 0;
        for (int bananas : piles) {
            time += Math.ceil((float) bananas / speed);
        }
        return time <= h;
    }

}
