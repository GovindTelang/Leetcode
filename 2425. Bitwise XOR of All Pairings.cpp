class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       int m = nums2.size();
       int s = 0;
       if(n%2==0 && m%2==0) return 0;
       else if(n%2 && m%2==0){
        for(int it : nums2){
         s ^= it;
        } 
        return s;
       }
       else if(n%2==0 && m%2){
        for(int it : nums1){
         s ^= it;
        }
        return s;
       }  
       else{
         for(int it : nums1){
         s ^= it;
        }
         for(int it : nums2){
         s ^= it;
        }
       }
       return s;
    }
};
