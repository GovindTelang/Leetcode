class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int zero = 0;
      int ans = 0;
      int currstart = 0;
      for(int i=0;i<nums.size();i++){
        zero += nums[i]==0;
        while(zero > 1){
            zero -= nums[currstart]==0;
            currstart++;
        }
        ans = max(ans,i-currstart);
      }
      return ans;
    }
};
/* This algorithm will cover the edge case with no zeroes, as in that case, the zeroCount will never exceed 1, and our window will cover the whole array. In the end, the difference between the first and last index would provide the array size minus 1, which is intended as we need to delete one element.
 0   1  1  1  0 
 cur          i 
 0   1   1  1  0 
     cur       i  atmost one zero (0 zeros in the case of all ones) length = i-curr = 3 here 
yaha par automatically 1 element ko consider nhi kr rhe same as removing it */
