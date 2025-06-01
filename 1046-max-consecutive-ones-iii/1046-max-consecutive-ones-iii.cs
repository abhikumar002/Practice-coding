public class Solution {
    public int LongestOnes(int[] nums, int k) {
        int count = 0;
        int left = 0, right = 0;
        int ans = 0;

        while(right < nums.Length){
            if(nums[right] == 0) count++;

            while(count > k){
                if(nums[left] == 0) count--;
                left++;
            }

            ans = Math.Max(ans, right - left + 1);
            right++;
        }

        return ans;
        
    }
}