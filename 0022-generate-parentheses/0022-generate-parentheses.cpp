class Solution {
public:
    vector<string> recursion(vector<string>& ans, string temp,int left, int right, int n){
        
        if(temp.size() == 2*n){
            ans.push_back(temp);
            return ans;
        }
          
        if(left < n){
            temp.push_back('(');
            recursion(ans,temp,left+1,right,n);
            temp.pop_back();
        }
        if(right < left){
            temp.push_back(')');
            recursion(ans,temp,left,right+1,n);
            temp.pop_back();
        }
        return ans;

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        return recursion(ans,"",0,0,n);
    }
};