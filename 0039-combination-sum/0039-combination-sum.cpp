class Solution {
public:
    vector<vector<int>> recursion(vector<vector<int>>& ans, vector<int>& temp, int index, int target, vector<int>& arr){
        
        if(target == 0)
        {
            ans.push_back(temp);
            return ans;
        }

        if(index == arr.size()){
            return ans;
        }

        if(target < 0) return ans;

        temp.push_back(arr[index]);
        recursion(ans,temp,index,target-arr[index],arr);
        temp.pop_back();
        recursion(ans,temp,index+1,target,arr);
        return ans;

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();

        return recursion(ans,temp,0,target,nums);
    }
};