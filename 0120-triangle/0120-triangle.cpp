class Solution {
public:
    // int recursion(vector<vector<int>>& dp,vector<vector<int>>& triangle, int row, int col){
    //     if(row == 0 && col == 0) return triangle[0][0];
    //     if(row < 0 || col < 0 || col > row) return 1e5;

    //     if(dp[row][col] != -1) return dp[row][col];
    //     int right = triangle[row][col] + recursion(dp,triangle,row-1,col);
    //     int left = triangle[row][col] + recursion(dp,triangle,row-1,col-1); 
    //     dp[row][col] = min(left,right);
    //     return dp[row][col];
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int ans = INT_MAX;
        vector<vector<int>>tab(m,vector<int>(m,0));

        for(int col=0;col<n;col++){
            tab[m-1][col] = triangle[m-1][col];
        }
        

        for(int row=m-2;row>=0;row--){
            for(int col=0;col<=row;col++){
                int right = tab[row+1][col];
                int left = tab[row+1][col+1]; 
                tab[row][col] = triangle[row][col] + min(left,right); 
            }   
        }
        return tab[0][0];
    }
};