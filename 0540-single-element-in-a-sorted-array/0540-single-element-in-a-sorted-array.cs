public class Solution {
    public int SingleNonDuplicate(int[] nums) {
        int n = nums.Length;
        int l = 0;
        int h = n-1;

        while(l<h){
            int m = l + (h-l)/2;
            
            if(m%2 == 1) m--;

            if(nums[m] == nums[m+1]) l = m +2;
            else  h = m;
        }

        return nums[l];
    }
}