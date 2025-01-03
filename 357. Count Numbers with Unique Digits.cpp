class Solution {
public:
   long long help(int n){
        if(n<=1) return 0;
        long ans = 9;
        int x = 9;
        n--;
        while(n--){
            ans *= x;
            x--;
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
     if(n==0) return 1;
     if(n==1) return 10;
     long long prev = 10;
     long long curr = 0;
     for(int i=2;i<=n;i++){
        curr = prev+help(i);
        prev = curr;
     }
     return curr;
   /* ALSO CORRECT  
     vector<long long> dp(9,0);
     dp[0]=1;
     dp[1]=10;
     for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+help(i);
     }
     return dp[n]; */
    }
};
