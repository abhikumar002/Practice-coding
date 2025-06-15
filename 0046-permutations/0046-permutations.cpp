class Solution {
public:

    void recursion(vector<vector<int>>& ans,vector<int>& visited, vector<int> temp,int index, vector<int>& nums){
        
        if(nums.size() == temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(visited[i] == -1){
                visited[i] = 0;
                temp.push_back(nums[i]);
                recursion(ans,visited,temp,index+1,nums);
                visited[i] = -1;
                temp.pop_back();
            }
        }  

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> v(n,-1);

        recursion(ans,v,{},0,nums);
        return ans;
    }
};