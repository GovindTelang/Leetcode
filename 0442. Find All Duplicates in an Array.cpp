class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        vector<int> res;
        for(auto &num : nums){
            mp[num]++;
            if(mp[num]>1) res.push_back(num);//Each element in nums appears once or twice.
            //since it can appear only once or twice hence this if statement will work only once if it works and hence the same number will not come in ans twice
        }
       
        return res;

    }
};
