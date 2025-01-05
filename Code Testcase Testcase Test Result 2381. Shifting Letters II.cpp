class Solution {
public:
    void help(int s,int e,int val,vector<int> &v){
        for(int i=s;i<=e;i++){
            v[i]+=val;
        }
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefix_sum(s.size()+1,0);
        string ans = "";
        for(auto x : shifts){
            int add = x[2]>0 ? 1 : -1;
            int start = x[0];
            int end = x[1];
            prefix_sum[start] += add;
            prefix_sum[end+1] += (-1)*(add);
        }
        for(int i=1;i<prefix_sum.size();i++){
            prefix_sum[i] += prefix_sum[i-1];
        }
        for(int i=0;i<s.size();i++){
           if(prefix_sum[i]==0){
            ans += s[i];
            continue;
           }
           int y = s[i]-'a';
           prefix_sum[i] %= 26;
           y = (y+prefix_sum[i]+26)%26;
           ans += y+'a';
        }
        return ans;
    }
};
