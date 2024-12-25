class Solution {
    /* also correct solution
int countVowelStrings(int n) {
    int a = 1,b = 1,c = 1,d = 1,e = 1;
    for(int i=2;i<=n;i++){
        a = a+b+c+d+e;
        b = b+c+d+e;
        c = c+d+e;
        d = d+e;
        e = e;
    }    
    return a+b+c+d+e;
    }
    */
public:
    int help(int i,int n,string &s,vector<vector<int>> &dp){
        if(n==0) return 1;
        if(i==s.size()) return 0;
        if(dp[i][n]!=-1) return dp[i][n];  //why dp[i][n] or 2d dp as here i and n are varying in recursive solution
        int pick = help(i,n-1,s,dp);
        int not_pick = help(i+1,n,s,dp);
        return dp[i][n]=pick+not_pick;
    }
    int countVowelStrings(int n) {
     string s = "aeiou";
     vector<vector<int>> dp(5,vector<int>(n+1,-1));
     return help(0,n,s,dp);
    }
};
