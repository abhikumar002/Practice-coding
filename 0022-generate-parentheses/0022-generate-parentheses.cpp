class Solution {
public:
    vector<string> recursion(int n,int left, int right,string temp, vector<string>& ans){
        if(temp.size() == 2*n){
            ans.push_back(temp);
            return ans;
        }

        if(left < n){
            temp.push_back('(');
            recursion(n,left+1,right,temp,ans);
            temp.pop_back();
        }

        if(right < left){
            temp.push_back(')');
            recursion(n,left,right+1,temp,ans);
            temp.pop_back();
        }
        return ans;

    }
    
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> ans;
        return recursion(n,0,0,temp,ans);
    }
};