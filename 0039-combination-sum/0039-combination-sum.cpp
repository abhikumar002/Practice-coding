class Solution {
public:
    void SolveSum(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(target < 0 || index >= candidates.size()) return;

        //lena hai
        temp.push_back(candidates[index]);
        SolveSum(index, candidates, target-candidates[index], ans, temp);
        temp.pop_back();

        //nhi lena
        SolveSum(index+1, candidates, target, ans, temp);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;

        SolveSum(0, candidates, target, ans, temp);
        return ans;
    }
};