class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<p,vector<p>,greater<p>> pq;
    map<int,int> mp;
    for(auto &num : nums){
        mp[num]++;
    }
    for(auto it : mp){
        pq.push({it.second,it.first});
        if(pq.size()>k) pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
    }
};
