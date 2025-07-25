class Solution {
public:
      bool help(string s, int ind, unordered_set<string> &st, vector<int> &dp) {
        if (ind == s.size()) return true;
        if (dp[ind] != -1) return dp[ind];

        for (int end = ind; end < s.size(); end++) {
            string word = s.substr(ind, end - ind + 1);
            if (st.count(word)) {
                if (help(s, end + 1, st, dp)) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return help(s, 0, st, dp);
    }
};
