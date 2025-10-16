class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> v;

        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        v.push_back(pq.top().first);
        
        for(int i=k;i<nums.size();i++){
            pq.push({nums[i],i});
            while(pq.top().second-i < 1-k) pq.pop();

            v.push_back(pq.top().first);
        }

        return v;
    }
};