class Solution {
public:
    
    bool recursion(int n,int i,int j, vector<vector<char>>& board, string word){
        
        if(n == word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j] !=word[n]) return false;

        board[i][j] = '0';
        bool ans = recursion(n+1,i+1,j,board,word) || 
                   recursion(n+1,i,j+1,board,word) ||
                   recursion(n+1,i-1,j,board,word) ||
                   recursion(n+1,i,j-1,board,word);

        board[i][j] = word[n];
        return ans;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> ans;
        int n = board.size();
        int m = board[0].size();

        if(word == "") return false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0] && recursion(0,i,j,board,word)) return true;
            } 
        } 
        return false;
    }
};