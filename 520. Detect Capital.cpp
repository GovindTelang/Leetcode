class Solution {
public:
    bool detectCapitalUse(string word) {
    /* int n = word.size();
     if(n==1) return true;
     char ch = word[0];
     if(!isupper(ch)){
        for(int i=1;i<n;i++){
            if(isupper(word[i])) return false;
        }
     }
     else if(isupper(ch) && isupper(word[1])){
        for(int i=2;i<n;i++){
            if(!isupper(word[i])) return false;
        }
     }
     else{
        for(int i=1;i<n;i++){
            if(isupper(word[i])) return false;
        }
     }
     return true;
     */
        int n = word.size();
        if (n == 1) return true;

        // Check the case of the second character to decide the pattern
        if (isupper(word[0]) && isupper(word[1])) {
            // All characters must be uppercase
            for (int i = 2; i < n; i++) {
                if (!isupper(word[i])) return false;
            }
        } else {
            // All characters except the first must be lowercase
            for (int i = 1; i < n; i++) {
                if (isupper(word[i])) return false;
            }
        }
        return true;
    }
};
