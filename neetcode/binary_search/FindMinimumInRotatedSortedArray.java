class Solution {
    public int findMin(int[] nums) {
        
        int low = 0, high = nums.length - 1;

        while (low < high) {

            if (nums[low] <= nums[high]) {
                return nums[low];
            }

            int mid = (high + low) / 2;
            if (nums[mid] < nums[low]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }

        }

        return nums[high % nums.length];

    }
}