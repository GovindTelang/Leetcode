class Solution {
public:
    int maxScore(string s) {
       int n = s.size();
       int ones = 0;
       int ans = 0;
       for(int i=0;i<n;i++){
        if(s[i]=='1') ones++;
       } 
       int zero = 0;
       for(int i=0;i<n-1;i++){  // after splitting the string into two non-empty substrings (i.e. left substring and right substring)
        if(s[i]=='1') ones--;
        else zero++;
        ans = max(ans,zero+ones);
       }
       return ans;
    }
};
