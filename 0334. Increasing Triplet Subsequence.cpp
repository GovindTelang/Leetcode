class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int low = INT_MAX;
        int mid = INT_MAX;
        for(int i=0;i<n;i++){
        if(nums[i]>mid) return true;
        if(nums[i]<mid && nums[i]>low) mid = nums[i];
        else if(nums[i]<low) low=nums[i];
        }
        return false;
    }
};
