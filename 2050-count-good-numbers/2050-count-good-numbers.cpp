long long MOD = 1000000007;
class Solution {
public:
    long long power(long long n, long long x){ //5
        if(x == 1) return n;
        if(x<1) return 1;

        long long half = power(n,x/2); //1
        if(x%2 == 0){
            return (half*half) % MOD;
        }
        else{
            return (half*half*n) % MOD ;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = n/2 + n%2;
        long long odd = n/2;

        long long a = power(5, even); //5,3
        long long b = power(4, odd); // 4,2
        return ((a*b) % MOD);
    }
};