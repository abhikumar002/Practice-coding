public class Solution {
    public void Rotate(int[] nums, int k) {
        int n = nums.Length;
        if(k > n) k = k % n;

        int length = n-k;
        Array.Reverse(nums,0,length);
        Array.Reverse(nums,length,k);
        Array.Reverse(nums,0,n);
        return;
    }
}