class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int low = -1, high = matrix.length - 1; // find row...
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (matrix[mid][0] <= target) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }

        if (low == -1) {
            return false;
        }
        int row = low;

        low = 0; high = matrix[row].length - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;

    }
}
