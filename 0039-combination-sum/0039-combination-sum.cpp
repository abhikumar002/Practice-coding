class Solution {
public:
    void recursion(int index, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target){
        if(index < 0 || target < 0 )  return;
        if(target == 0) { ans.push_back(temp); return; }

        temp.push_back(candidates[index]);
        recursion(index,candidates, ans, temp, target - candidates[index]); // take
        temp.pop_back();
        recursion(index-1,candidates, ans, temp, target); // non-take

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;

        recursion(n-1,candidates, ans, temp, target);
        return ans;
    }
};