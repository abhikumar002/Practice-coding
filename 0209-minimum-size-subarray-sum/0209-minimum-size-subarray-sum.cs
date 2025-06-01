public class Solution {
    public int MinSubArrayLen(int target, int[] nums) {
        int ans=int.MaxValue;
        int right=0,left=0,sum=0;
        
        while(right<nums.Length){
            sum+=nums[right];
            while(sum>=target){
                sum-=nums[left];
                ans=Math.Min(right-left+1,ans);
                left++;
            }
            right++;
        }
        if(ans== int.MaxValue) return 0;
        return ans;
    }
}