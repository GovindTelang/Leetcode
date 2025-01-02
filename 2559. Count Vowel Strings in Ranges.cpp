class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    bool isVowStr(string s){
        return isVowel(s[0]) && isVowel(s[s.size()-1]);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
       int n = queries.size();
       vector<int> ans(n,0);
       vector<int> pref(words.size(),0);
       if(isVowStr(words[0])) pref[0] = 1;
       else pref[0] = 0;
       for(int i=1;i<words.size();i++){
        string x = words[i];
        if(isVowStr(x)){
            pref[i]=pref[i-1]+1;
        }
        else pref[i]=pref[i-1];
       }
       int ele = 0;
       for(auto it : queries){
        int a = it[0];
        int b = it[1];
        if(a==b) ans[ele++] = isVowStr(words[a]) ? 1 : 0;
        else if(a==0) ans[ele++] = pref[b];
        else ans[ele++] = pref[b]-pref[a-1];
       }
       return ans; 
    }
};
