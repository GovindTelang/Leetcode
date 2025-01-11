class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp;
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        int count = mp.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                if(st.size()==count) ans++;   //this will be subarray from i to j ie. from 0-0 0-1 0-2 etc.
            }
           // st.clear();
        }
        return ans;
    }
};
