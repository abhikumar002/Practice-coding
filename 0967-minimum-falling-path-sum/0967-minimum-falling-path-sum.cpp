class Solution {
public:
    // int recursion(vector<vector<int>>& dp,vector<vector<int>>& triangle, int row, int col){
    //     int n = triangle.size();
    //     if(row < 0 || col < 0 || row > n-1 || col > n-1) return 1e5;
    //     if(row == 0) return triangle[0][col];
        

    //     if(dp[row][col] != -1) return dp[row][col];
    //     int dia =  triangle[row][col] + recursion(dp,triangle,row-1,col+1);
    //     int right = triangle[row][col] + recursion(dp,triangle,row-1,col);
    //     int left = triangle[row][col] + recursion(dp,triangle,row-1,col-1); 
    //     dia = min(dia,left);
    //     dp[row][col] = min(dia,right);
    //     return dp[row][col];
    // }

    int minFallingPathSum(vector<vector<int>>& triangle) {

        int m = triangle.size();
        if (m == 0) return 0;

        vector<vector<int>>tab(m,vector<int>(m,0));

        for (int col = 0; col < m; ++col) {
            tab[0][col] = triangle[0][col];
        }

        for (int row = 1; row < m; ++row) {
            for (int col = 0; col < m; ++col) {

                int up_left = (col > 0) ? tab[row-1][col-1] : INT_MAX;
                int up = tab[row-1][col];
                int up_right = (col  < m-1) ? tab[row-1][col+1]: INT_MAX;

                tab[row][col] = triangle[row][col] + min({up_left, up, up_right});   
            }
        }
        return *min_element(tab[m-1].begin(), tab[m-1].end());

    }
};


// int m = matrix.size();
// int ans = INT_MAX;
// int temp = INT_MAX;
// vector<vector<int>>tab(m+1,vector<int>(m+1,0));

// for(int col=0;col<m;col++){
//     tab[m-1][col] = matrix[m-1][col];
// }

// for(int row=m-2;row>=0;row--){
//     for(int col=1;col<m-1 ;col++){
//         cout<<row<<" "<<col<<endl;
//         int dia = tab[row+1][col-1];
//         int right = tab[row+1][col];
//         int left = tab[row+1][col+1]; 
//         temp = min(left,right);
//         tab[row][col] = matrix[row][col] + min(temp,dia); 
//     }   
// }
// return ans;