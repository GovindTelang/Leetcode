class Solution {
public:
    void expand(string s,int i,int j,int &start,int &maxLen){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            if(maxLen < j-i+1){
                maxLen = j-i+1;
                start = i;
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        //best method is expansion
    int n = s.size();
    if(n<=1) return s;
    int start = 0;
    int maxLen = 1;
    for(int i=0;i<n;i++){
        expand(s,i,i,start,maxLen); // expand around the odd center
        expand(s,i,i+1,start,maxLen); // expand around the even center
    }
    return s.substr(start,maxLen);    
    }
};
