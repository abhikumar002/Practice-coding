public class Solution {
    public int Search(int[] nums, int target) {
        
        int n = nums.Length;
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(target == nums[mid]) return mid;
            if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }

        return -1;    
    }
}