class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
       /* int n = nums.size();
        //int cnt = k;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                int cnt = 0;
                i++;
                while(i<n && nums[i]!=1){
                    i++;
                    cnt++;
                }
                if(cnt < k) return false;
            }
        }
        return true;*/
        /*After you detect a 1, you immediately move i++ and start counting zeros until the next 1.But if that next 1 does not exist (i.e., it was the last 1 in the array), your code still checks*/
        int prev = -1;  // position of previous 1
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(prev != -1 && i - prev - 1 < k) {
                    return false;
                }
                prev = i;  // update previous 1's position
            }
        }
        return true;
    }
};
