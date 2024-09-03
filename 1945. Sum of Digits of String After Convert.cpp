class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";
        for(char it : s){
            ans += to_string(it-'a'+1);
        }
        int res;
        while(k--){
        res = 0;
        for(int i=0;i<ans.size();i++){
        res += (ans[i]-'0');
        }
        ans = to_string(res);
        }
        return res;
    }
};
