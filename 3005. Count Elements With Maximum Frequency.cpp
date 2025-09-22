class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int> mp;
       int n = nums.size();
       int maxo = 0;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
        maxo = max(maxo,mp[nums[i]]);
       } 
       int cnt = 0;
       for(auto it : mp){
        if(it.second == maxo){
            cnt+=maxo;
        }
       }
       return cnt;
    }
};
