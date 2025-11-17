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
        SolveSum(index+1, candidates, target-candidates[index], ans, temp);
        temp.pop_back();

        int nextIndex = index+1;
        while(nextIndex < candidates.size() && candidates[nextIndex] == candidates[index]){
            nextIndex++;
        }

        //nhi lena
        SolveSum(nextIndex, candidates, target, ans, temp);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> duplicates;
        vector<int> temp;

        SolveSum(0, candidates, target, duplicates, temp);

        set<vector<int>> single(duplicates.begin(),duplicates.end());
        vector<vector<int>>ans(single.begin(), single.end());
        return ans;
    }
};