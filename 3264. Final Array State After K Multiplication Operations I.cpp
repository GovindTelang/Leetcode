class Solution {
public:
   static bool comp(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     for(int i=0;i<nums.size();i++){
        pq.push({nums[i],i});
     }
     int x = multiplier;
     while(k--){
        auto ch = pq.top();
        pq.pop();
        int idx = ch.second;
        int ele = ch.first;
        pq.push({ele*x,idx});
     }
     vector<pair<int,int>> ans;
     while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
     }
     sort(ans.begin(),ans.end(),comp);
     vector<int> res;
     for(auto it: ans){
        res.push_back(it.first);
     }  
     return res;
    }
};
