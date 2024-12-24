class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector<int> refund;
        int ans = 0;
        for(auto x : costs){
            ans += x[0];
            refund.push_back(x[1]-x[0]);
        }
        sort(refund.begin(),refund.end());
        for(int i=0;i<n;i++){
            ans += refund[i];
        }
        return ans;
    }
};
