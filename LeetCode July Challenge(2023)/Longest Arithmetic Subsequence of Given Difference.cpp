class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int ans = 1;
        unordered_map<int, int> dp;
        for (auto &val : arr) {
            if (!dp.count(val - difference))
                dp[val] = 1;
            else
                dp[val] = dp[val - difference] + 1;
            ans = max(ans, dp[val]);
        }
        return ans;
    }
};