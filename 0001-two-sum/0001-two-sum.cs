public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> dic = new Dictionary<int,int>();
        int[] ans = new int[2];

        for(int i=0;i<nums.Length;i++){
            int temp = target - nums[i];

            if(dic.ContainsKey(temp)){
                return new[] {dic[temp],i};
            }
            
            if(!dic.ContainsKey(temp)){
                dic[nums[i]] = i;
            }
        }

        return new int[0];
    }
}