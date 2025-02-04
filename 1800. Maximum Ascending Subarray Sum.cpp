class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currMaxSum = nums[0];
        for(int curridx = 1;curridx<nums.size();curridx++){
            if(nums[curridx]<=nums[curridx-1]){
                maxSum = max(maxSum,currMaxSum);
                currMaxSum = 0;
            }
            currMaxSum += nums[curridx];
        }
        return max(maxSum,currMaxSum);
    }
};
