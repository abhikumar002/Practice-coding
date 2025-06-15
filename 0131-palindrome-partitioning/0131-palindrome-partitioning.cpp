class Solution {
public:

    bool palindrome(string s,int first,int end){
        while(first<=end){
            if(s[first++] !=s[end--]) return false;
        }
        return true;
    }

    void recursion(vector<vector<string>>& ans, vector<string>& temp, int index, string s){
        
        if(index == s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i = index;i<s.length();i++){
            if(palindrome(s,index,i)){
                temp.push_back(s.substr(index, i - index + 1));
                recursion(ans,temp,i+1,s);
                temp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recursion(ans,temp,0,s);
        return ans;
    }
};