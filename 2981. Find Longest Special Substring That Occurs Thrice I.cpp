class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string,int> govi;
        for(int i=0;i<n;i++){
            string curr = "";
            for(int j=i;j<n;j++){
            if(curr.empty() || curr.back()==s[j]){
                curr += s[j];
                govi[curr]++;
            }
            else break;
            }
        }
        int ans = 0;
        for(auto it : govi){
            string st = it.first;
            int count = it.second;
            if(count >= 3 && st.length()>ans){
                ans = st.length();
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
