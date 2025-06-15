class Solution {
public:
    set<vector<int>> recursion(set<vector<int>>& ans, vector<int>& temp, int index, int target, vector<int>& arr){
        if(target == 0)
        {
            ans.insert(temp);
            return ans;
        }

        if(index == arr.size()){
            return ans;
        }

        if(target < 0) return ans;

        if(arr[index]<=target){
            temp.push_back(arr[index]);
            recursion(ans,temp,index+1,target-arr[index],arr);
            temp.pop_back();
        }

        int nextIndex = index + 1;
        while (nextIndex < arr.size() && arr[nextIndex] == arr[index]) {
            nextIndex++;
        }

        recursion(ans, temp, nextIndex, target, arr);
        return ans;

    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        //vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        set<vector<int>> ans;

        ans = recursion(ans,temp,0,target,nums);
        
        vector<vector<int>> t(ans.begin(),ans.end());
        return t;
    }
};