public class Solution {

    public int subarraysum(int[] nums, int goal){
        int low = 0, high = 0, ans = 0, sum = 0;

        while(high < nums.Length){

            sum += nums[high];

            while(low <= high && sum > goal){         
                sum -= nums[low];
                low++;
            }

            ans += (high - low +1);
            high++;
        }

        return ans;
    }

    public int NumSubarraysWithSum(int[] nums, int goal) {
        return subarraysum(nums,goal) - subarraysum(nums,goal-1);
    }

}