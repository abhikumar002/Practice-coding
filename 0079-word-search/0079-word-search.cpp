class Solution {
public:
    bool recursion(int n, int row, int col, vector<vector<char>>& board, string word){
        if(n == word.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || board[row][col] != word[n]) return false;

        board[row][col] = '0';
        bool ans = recursion(n+1, row+1, col, board, word) || 
                   recursion(n+1, row, col+1, board, word) || 
                   recursion(n+1, row-1, col, board, word) || 
                   recursion(n+1, row, col-1, board, word);

        board[row][col] = word[n];
        return ans;
    } 

    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;

        for(int i =0 ;i<board.size();i++){
            for(int j =0 ;j<board[0].size();j++){
                if((board[i][j] == word[0]) && recursion(0, i, j, board, word)) return true;
            }
        }

        return false;
    }
};