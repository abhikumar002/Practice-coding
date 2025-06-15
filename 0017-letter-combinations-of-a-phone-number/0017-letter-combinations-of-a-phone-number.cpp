class Solution {
public:
    vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> recursion(vector<string>& ans,string temp,int index, string digits){
        
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return ans;
        }

        string s = v[digits[index]-'0'];
        for(auto c : s){
            temp.push_back(c);
            recursion(ans,temp,index+1,digits);
            temp.pop_back();
        }       
        return ans;

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        return recursion(ans,"",0,digits);
    }
};