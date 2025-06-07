public class Solution {
    public int lowestsearch(int[] nums){
        int n = nums.Length;
        if(nums[0] < nums[n-1]) return 0;

        int left = 0;
        int right = n-1;
        int ans = int.MaxValue;
        int t = ans;

        while(left <= right){
            int mid = (left + right)/2;
            Console.WriteLine(mid);
            if(ans > nums[mid]){
                ans = nums[mid];
                t = mid;
            }
            if(nums[mid] < nums[right]) right = mid-1;
            else left = mid+1;
        }

        return t;
    }

    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int left = 0;
        int right = n-1;

        int low = lowestsearch(nums);
        Console.WriteLine(low);
        if(nums[low] < target && nums[right] < target) right = low;
        //1 < 2 && 
        else left = low;

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid+1;
            else right = mid -1;
        }

        return -1;
    }
}