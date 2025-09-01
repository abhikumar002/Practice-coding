public class Solution {
    public long checkhour(int[] piles, int h){
        long requiretime = 0;
        
        for(int i=0;i<piles.Length;i++){
            requiretime +=(long)Math.Ceiling((double)piles[i] /(double)h);
        }
        
        return requiretime;
    }

    public int MinEatingSpeed(int[] piles, int h) {
        Array.Sort(piles);
        int n = piles.Length;
        int low = 1;
        int high = piles[n-1];

        while(low<=high){
            int mid = (low+high)/2;
            //Console.WriteLine(mid + " "+low+" "+high);
            long totalhour = checkhour(piles,mid);
            //Console.WriteLine(totalhour);
            if(totalhour <= h) high = mid-1;
            else low = mid+1;
        }

        return low;
    }
}