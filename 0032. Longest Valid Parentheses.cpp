class Solution {
public:
    int longestValidParentheses(string s) {
       int n = s.size();
       int mx1 = 0;
       int mx2 = 0;
       int open = 0;
       int close = 0;
       for(int i=0;i<n;i++){
       if(s[i]=='(') open++;
       else close++;
       if(open<close){
        open=0;
        close=0;
       }
       else if(open==close){
        mx1 = max(mx1,2*open);
       }
       }
       open=close=0;
       for(int i=n-1;i>=0;i--){
       if(s[i]==')') open++;
       else close++;
       if(open<close){
        open=0;
        close=0;
       }
       else if(open==close){
        mx2 = max(mx2,2*open);
       }
       }
       return max(mx1,mx2); 
    }
};
