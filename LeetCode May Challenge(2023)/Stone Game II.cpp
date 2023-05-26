class Solution {
public:
    int get(int l, int r, vector<long long> &pref) {
        return pref[r + 1] - pref[l];
    }
    int help(int idx, int m, bool aliceTurn, vector<long long> &pref, vector<int> &piles, vector<vector<vector<int>>> &dp) {
        if (idx >= piles.size())
            return 0;
        if (dp[idx][m][aliceTurn] != -1)
            return dp[idx][m][aliceTurn];
        if (aliceTurn) {
            int ans = 0;
            for (int x = 1; x <= 2 * m; x++)
                if (idx + x - 1 < piles.size())
                    ans = max(ans, get(idx, idx + x - 1, pref) + help(idx + x, max(m, x), false, pref, piles, dp));
            return dp[idx][m][aliceTurn] = ans;
        }
        int ans = 1e9;
        for (int x = 1; x <= 2 * m; x++)
            if (idx + x - 1 < piles.size())
                ans = min(ans, help(idx + x, max(m, x), true, pref, piles, dp));
        return dp[idx][m][aliceTurn] = ans;
    }
    int stoneGameII(vector<int> &piles) {
        int n = piles.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + piles[i - 1];
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 * n + 2, vector<int>(2, -1)));
        return help(0, 1, true, pref, piles, dp);
    }
};