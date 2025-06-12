public class Solution {
    public double recursion(double x, long n){
        if(n == 0) return 1;
        double half = recursion(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }

    public double MyPow(double x, int n) {

        long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        return recursion(x, N);
    }
}