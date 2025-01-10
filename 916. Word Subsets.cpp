class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        for(auto &s : words2){
            vector<int> nfreq(26,0);
            for(auto &c : s){
                nfreq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                freq[i] = max(freq[i],nfreq[i]);
            }
        }
        vector<string> ans;
        for(auto &s : words1){
            vector<int> nfreq(26,0);
            bool ok = true;
            for(auto &c : s){
                nfreq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                if(freq[i]>0 && freq[i]>nfreq[i]){
                    ok=false;
                    break;
                }
            }
            if(ok) ans.push_back(s);
        }
        return ans;
    }
};
