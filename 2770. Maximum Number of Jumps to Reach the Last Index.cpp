class Solution {
public:
    int help(int ind,vector<int> &dp,vector<int> &nums,int target){
        if(ind == nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res = INT_MIN;
        for(int j = ind+1; j<nums.size();j++){
            if(abs(nums[j]-nums[ind]) <= target){
                res = max(res,1+help(j,dp,nums,target));
            }
        }
        return dp[ind]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = help(0,dp,nums,target);
        return ans<0 ? -1 : ans;
    }
};
