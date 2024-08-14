class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());
        vector<int> vec(maxEle+1,0);
        //for each distance d how many pairs are there 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){//i+1 se isliye taki same element ko waapis na lele 
                int d = abs(nums[i]-nums[j]);
                vec[d]++;
            }
        }
        for(int d=0;d<maxEle+1;d++){
            k-=vec[d];
            if(k<=0) return d;
        }
        return -1;
    }
};
