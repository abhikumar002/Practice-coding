public class Solution {
    public int[] SortedSquares(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];
        
        // for(int i=0;i<nums.Length;i++){
        //     nums[i] = nums[i]*nums[i];
        // }


        int left = 0; int right = n-1;
        for(int i=n-1;i>=0;i--){
            if(Math.Abs(nums[left]) > Math.Abs(nums[right])){
                ans[i] = nums[left]*nums[left];
                left++;
            }
            else{
                ans[i] = nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
}