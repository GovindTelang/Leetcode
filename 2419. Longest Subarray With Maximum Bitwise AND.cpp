class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                ans++;
                res=max(res,ans);
            }
            else ans=0;
        }
        return res;
    }
};
