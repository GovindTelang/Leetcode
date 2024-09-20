class Solution {
public:
    string shortestPalindrome(string s) {
    string r = s;
    reverse(r.begin(),r.end());
    for(int i=0;i<s.length();i++){
        if(!memcmp(s.c_str(), r.c_str() + i, s.length()-i)){
            return r.substr(0,i) + s;
        }
    }
    return r + s;
    }
};
