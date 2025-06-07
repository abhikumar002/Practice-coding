public class Solution {

    public int bound(int[] nums, int target, bool findfirst){
        int n = nums.Length;
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] > target) high = mid-1;
            else if(nums[mid] < target) low = mid +1;
            else{
                ans = mid;
                if(findfirst){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            } 
        }

        return ans;
    }

    public int[] SearchRange(int[] nums, int target) {        
        return [bound(nums,target,true),bound(nums,target,false)];
    }
}