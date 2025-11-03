class Solution {
public:
    vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void recursion(int index, string s, string digits, vector<string>& ans) {
        if(s.size() == digits.size()){
            ans.push_back(s);
            return;
        }

        string str = v[digits[index] - '0'];

        for(auto c : str){
            s.push_back(c);
            recursion(index+1,s,digits,ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        recursion(0,"",digits,ans);
        return ans;
    }
};