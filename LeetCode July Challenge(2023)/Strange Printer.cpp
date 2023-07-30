class Solution {
public:
    int solveMem(string &s, int left, int right, vector<vector<int>> &dp) {
        if (left == right)
            return 1;
        if (dp[left][right] != -1)
            return dp[left][right];
        int ans = INT_MAX, tmp;
        for (int k = left; k < right; k++) {
            tmp = solveMem(s, left, k, dp) + solveMem(s, k + 1, right, dp);
            ans = min(ans, tmp);
        }
        if (s[left] == s[right])
            ans--;
        dp[left][right] = ans;
        return ans;
    }
    int strangePrinter(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, -1));
        return solveMem(s, 0, len - 1, dp);
    }
};