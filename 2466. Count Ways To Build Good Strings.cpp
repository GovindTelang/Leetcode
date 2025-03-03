class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
     //this int dp[100001]={0}; or
     vector<int> dp(high+1,0);
     dp[0]=1;
     int mod = 1e9+7;
     for(int end=1;end<=high;end++){
        if(end>=zero){
            dp[end] += dp[end-zero];
        }
        if(end>=one){
            dp[end] += dp[end-one];
        }
        dp[end] %= mod;
     }
     int soln = 0;
     for(int i=low;i<=high;i++){
        soln += dp[i];
        soln %= mod;
     }
     return soln;
    }
};
