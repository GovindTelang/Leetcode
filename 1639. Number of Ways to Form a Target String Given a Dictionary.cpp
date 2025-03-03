class Solution {
    vector<vector<int>>dp;
    vector<vector<int>>freq;
    
    long getWords(vector<string>&words, string &target, int i, int j){
        if(j == target.size())return 1;
        if(i == words[0].size() || words[0].size() - i < target.size() - j) return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        long count = 0;
        int  curPos = target[j] - 'a';
        count += getWords(words, target, i + 1, j);
        count += freq[i][curPos] * getWords(words, target, i + 1, j + 1);
        
        return dp[i][j] = count % 1000000007;
    }
public:
    int numWays(vector<string>& words, string target) {
        dp.resize(words[0].size(), vector<int>(target.size(), -1));
        freq.resize(words[0].size(), vector<int>(26, 0));
        
        for(int i=0; i<words.size(); i++){
            for(int j = 0; j < words[0].size(); j++){
                int  curPos = words[i][j] - 'a';
                freq[j][curPos]++;
            }
        }
        return getWords(words,target,0,0);
    }
};
