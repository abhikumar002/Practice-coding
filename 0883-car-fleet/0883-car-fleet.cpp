class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int,double>> v;
        
        for(int i=0;i<n;i++){
            double temp = (double)(target - position[i]) / speed[i];
            v.push_back({position[i],temp});
        }

        sort(v.begin(),v.end());

        double maxi = v[n-1].second;
        int fleet = 1;

        for(int i = n-2;i>=0;i--){
            if (v[i].second >  maxi) {
                fleet++;
                maxi = v[i].second;
            }
        }

        return (n==0) ? 0 : fleet;
    }
};