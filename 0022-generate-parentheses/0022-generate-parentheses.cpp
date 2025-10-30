class Solution {
public:
    void recursion(int open, int close, string temp, vector<string>& ans) {
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }

        if(open > 0) recursion(open-1, close, temp + '(', ans);
        if(open < close) recursion(open, close-1, temp + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        recursion(n, n, temp, ans);

        return ans;
    }
};