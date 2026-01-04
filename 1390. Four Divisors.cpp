class Solution {
public:
    int count(int num){
        if(num<6) return 0;
        int cnt = 2;
        int sum = 1+num;
        for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
         sum += i;
         cnt+=1;
         if(i!=sqrt(num)) cnt += 1 ,sum += num/i;
        } 
        }
        return cnt ==4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
       int n = nums.size();
       int sum = 0;
       for(int i=0;i<n;i++){
         sum += count(nums[i]);
       }
       return sum; 
    }
};
