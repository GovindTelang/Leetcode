class Solution {
public:
     int countSubsets(vector<int>& nums, int index, int currentOr,
                     int targetOr,vector<vector<int>>& memo) {
        // Base case: reached the end of the array
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        if(memo[index][currentOr] != -1) return memo[index][currentOr];

        // Don't include the current number
        int countWithout = countSubsets(nums, index + 1, currentOr, targetOr, memo);

        // Include the current number
        int countWith =
            countSubsets(nums, index + 1, currentOr | nums[index], targetOr, memo);

        // Return the sum of both cases
        return memo[index][currentOr] = countWithout + countWith;
    }
    int countMaxOrSubsets(vector<int>& nums) {
       int maxOrValue = 0;
       int n = nums.size();
        for (int num : nums) {
            maxOrValue |= num;
        }
        vector<vector<int>> memo(n, vector<int>(maxOrValue + 1, -1));
        return countSubsets(nums, 0, 0, maxOrValue, memo);   
    }
};
