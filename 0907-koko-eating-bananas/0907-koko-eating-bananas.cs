public class Solution {
    
    public int FindMax(int[] piles){
        int maxi = int.MinValue;;
        
        for(int i=0;i<piles.Length;i++){
            maxi = Math.Max(maxi,piles[i]);
        }
        
        return maxi;
    }
    
    public long checkhour(int[] piles, int h){
        long requiretime = 0;
        
        for(int i=0;i<piles.Length;i++){
            requiretime +=(long)Math.Ceiling((double)piles[i] /(double)h);
        }
        
        return requiretime;
    }
    
    public int MinEatingSpeed(int[] piles, int h) {
        int n = piles.Length;
        int left = 1;
        int right = FindMax(piles);
        int ans = 0;
        
        while(left <= right){
            int hour = (left + right) / 2;
            long temp = checkhour(piles,hour);
            
            if(temp <= h) {
                right = hour - 1;
            }
            else left = hour + 1 ;
        }
        
        return left;
    }
}