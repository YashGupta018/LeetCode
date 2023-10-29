class Solution {
public:
    int numWays(int steps, int arrLen) {
        int MOD = 1000000007;
        int maxPosition = min(steps / 2, arrLen - 1);
        vector<long long> dp(maxPosition + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= steps; i++) {
            vector<long long> new_dp(maxPosition + 1, 0);
            for (int j = 0; j <= maxPosition; j++) {
                new_dp[j] = dp[j];
                if (j > 0)
                    new_dp[j] = (new_dp[j] + dp[j - 1]) % MOD;
                if (j < maxPosition)
                    new_dp[j] = (new_dp[j] + dp[j + 1]) % MOD;
            }
            dp = new_dp;
        }
        return dp[0];
    }
};