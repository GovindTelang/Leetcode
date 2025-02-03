class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incLen = 1;
        int decLen = 1;
        int maxLen = 1;
        for(int pos = 0; pos < nums.size()-1; pos++){
            if(nums[pos+1]>nums[pos]){
                incLen++;
                decLen = 1;
            }
            else if(nums[pos+1]<nums[pos]){
                incLen = 1;
                decLen++;
            }
            else{
                incLen = 1;
                decLen = 1;
            }
            maxLen = max(maxLen,max(incLen,decLen)); //important
        }
        return maxLen;
    }
};
