public class Solution {
    public int sumafter(int[] nums, int divisor) {
        int sum = 0;
        foreach (var x in nums)
        {
            sum += (int)Math.Ceiling((double)x / divisor);
        }
        return sum;
    }
    public int SmallestDivisor(int[] nums, int threshold) {
        int n = nums.Length;
        int low = 1;
        int high = nums.Max();
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            int value = sumafter(nums,mid);
            if(value <= threshold){
                ans = mid;
                high = mid - 1;
            } 
            else{
                low = mid+1;
            }
        }

        return ans;
    }
}