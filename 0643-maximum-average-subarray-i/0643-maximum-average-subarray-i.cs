public class Solution {
    public double FindMaxAverage(int[] nums, int k) {
        int count = 0;
        int low = 0;
        double sum = 0;
        double max = double.MinValue;

        for(int i = 0;i<nums.Length;i++){
            if(count < k){
                sum +=nums[i];
                count++;
            }
            else if(count == k){
                max = Math.Max(max,(double)(sum/(double)k));
                Console.WriteLine(max);
                sum +=nums[i];
                sum -=nums[low++];
            }
        }

        max = Math.Max(max,sum/k);

        return max;
    }
}