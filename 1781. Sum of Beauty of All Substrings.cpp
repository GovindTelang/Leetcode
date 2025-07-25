class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int max_f = 0;
                int min_f = INT_MAX;
                for(int f : freq){
                    if(f>0){
                        max_f = max(max_f,f);
                        min_f = min(min_f,f);
                    }
                }
                totalBeauty += max_f-min_f;
            }
        }
        return totalBeauty;
    }
};
