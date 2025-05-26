public class Solution {
    public int MaxProfit(int[] prices) {
        int min = int.MaxValue;
        int profit = 0;

        for(int i=0;i<prices.Length;i++){
            if(min > prices[i]){
                min = prices[i];
            }
            
            profit = Math.Max(profit,prices[i]-min);
        }

        return profit;
    }
}