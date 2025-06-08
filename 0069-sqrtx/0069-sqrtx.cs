public class Solution {
    public int MySqrt(int x) {
        long low = 0;
        long high = x;

        while(low<=high){ 
            long mid = low + (high-low)/2;

            long value = mid*mid;
            if(value == x) return (int)mid;
            if(value< x) low = mid+1;
            else high = mid-1;
        }

        return (int)low-1;
    }
}