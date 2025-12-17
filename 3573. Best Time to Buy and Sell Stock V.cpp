class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
          const long long NEG_INF = -1e18;

        // dp[t][0] = free
        // dp[t][1] = holding long
        // dp[t][2] = holding short
        vector<vector<long long>> dp(k + 2, vector<long long>(3, NEG_INF));

        // Start: no transaction, free
        dp[0][0] = 0;

        for (int price : prices) {

            // SAME TYPE as dp
            vector<vector<long long>> new_dp = dp;

            for (int t = 0; t <= k; t++) {

                // Free -> Buy -> Long
                new_dp[t][1] = max(new_dp[t][1], dp[t][0] - price);

                // Free -> Sell -> Short
                new_dp[t][2] = max(new_dp[t][2], dp[t][0] + price);

                // Close positions (complete transaction)
                new_dp[t + 1][0] = max(new_dp[t + 1][0],
                                       dp[t][1] + price);

                new_dp[t + 1][0] = max(new_dp[t + 1][0],
                                       dp[t][2] - price);
            }

            dp = new_dp;
        }

        // Answer must be FREE
        long long ans = 0;
        for (int t = 0; t <= k; t++) {
            ans = max(ans, dp[t][0]);
        }

        return ans;
    }
};
