class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int> vec(26,0);
        for(int i=0;i<n;i++){
            vec[s[i]-'a']++;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(vec[i]==0) continue;
            if(vec[i]%2==1) ans += 1;
            else if(vec[i]%2==0) ans += 2;
        }
        return ans;
    }
};
