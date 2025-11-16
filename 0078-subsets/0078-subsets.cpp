class Solution {
public:
    void recursion(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        recursion(index+1,nums,temp, ans);
        temp.pop_back();
        recursion(index+1,nums,temp, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        recursion(0, nums, temp, ans);
        return ans;
    }
};