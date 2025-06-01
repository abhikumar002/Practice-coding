public class Solution {
    public int SubarraySum(int[] nums, int k) {
        int sum = 0;
        int right = 0;
        int ans = 0;
        Dictionary<int,int> dic = new Dictionary<int,int>();
        dic[0] = 1;

        while(right < nums.Length){
            sum += nums[right];

            if(dic.ContainsKey(sum-k)){
                ans+=dic[sum-k];         
            }

            dic[sum] = dic.GetValueOrDefault(sum,0)+1;
            right++;
        }

        return ans;
    }
}

// 1 2 0 0 3
// 1 3 3 3 6