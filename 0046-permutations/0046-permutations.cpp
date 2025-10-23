class Solution {
public:
    void recursion(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& used) {
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            recursion(nums, ans, temp, used);
            used[i] = false;
            temp.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);

        recursion(nums, ans, temp, used);
        return ans;
    }
};