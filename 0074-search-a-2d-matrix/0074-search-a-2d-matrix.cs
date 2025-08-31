public class Solution {
    public bool SearchMatrix(int[][] nums, int target) {
        
        int n = nums.Length;
        int m = nums[0].Length;

        // vertical Search
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low+high)/2;
            if (nums[mid][0] <= target && target <= nums[mid][m - 1]) {
                low = mid;
                break;
            }
            if(nums[mid][0] < target) low = mid+1;
            else high = mid-1;
        }

        if (low < 0 || low >= n) return false;

        // horizontal Search
        int left = 0;
        int right = m-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(target == nums[low][mid]) return true;
            if(nums[low][mid] < target) left = mid+1;
            else right = mid-1;
        }

        return false;
    }
}