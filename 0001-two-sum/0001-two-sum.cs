public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> dic = new Dictionary<int,int>();

        for(int i=0;i<nums.Length ; i++){

            if(dic.ContainsKey(nums[i])) return [dic[nums[i]],i];
            int temp =  target - nums[i];
            
            dic[temp] = i;
        }

        return [];
    }
}