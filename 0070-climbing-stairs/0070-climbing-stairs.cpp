class Solution {
public:
    int StairsRecursive(int index,int n, int& ans,  vector<int>& v) {
        if(index == n){ return 1; }
        if(index > n){ return 0; }
        
        if(v[index] != -1) return v[index];
        v[index] = StairsRecursive(index+1, n, ans, v) + StairsRecursive(index+2, n, ans, v);

        return v[index];
    }

    int climbStairs(int n) {
        int ans = 0;
        vector<int>v(n+1,-1);
        return StairsRecursive(0,n,ans,v);
    }
};