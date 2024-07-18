class Solution {
    public int search(int[] nums, int target) {
        
        int low = 0, high = nums.length - 1;
        while (low <= high) {

            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            System.out.println(low + " " + mid + " " + high);

            // drop is right of mid
            if (nums[mid] > nums[high]) {
                if (target > nums[mid] || target < nums[low])
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            // drop is left of mid
            else {
                if (target < nums[mid] || target > nums[high])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

        }

        return -1;

    }
}
