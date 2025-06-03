public class Solution {
    public int FindMin(int[] nums) {
        int n = nums.Length;
        if(nums[0] < nums[n-1]) return nums[0];

        int left = 0;
        int right = n-1;
        int ans = int.MaxValue;
        int t = ans;

        while(left <= right){
            int mid = (left + right)/2;
            // Console.WriteLine(mid);
            if(ans > nums[mid]){
                ans = nums[mid];
                t = mid;
            }
            if(nums[mid] < nums[right]) right = mid-1;
            else left = mid+1;
        }

        return nums[t];
    }
}