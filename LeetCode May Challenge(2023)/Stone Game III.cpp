class Solution {
public:
    int get(int l, int r, vector<long long> &pref) {
        return pref[r + 1] - pref[l];
    }
    int help(int idx, bool aliceTurn, vector<long long> &pref, vector<int> &piles, vector<vector<int>> &dp) {
        if (idx >= piles.size())
            return 0;
        if (dp[idx][aliceTurn] != -1)
            return dp[idx][aliceTurn];
        if (aliceTurn) {
            int ans = -1e9;
            for (int x = 1; x <= 3; x++)
                if (idx + x - 1 < piles.size())
                    ans = max(ans, get(idx, idx + x - 1, pref) + help(idx + x, false, pref, piles, dp));
            return dp[idx][aliceTurn] = ans;
        }
        int ans = 1e9;
        for (int x = 1; x <= 3; x++)
            if (idx + x - 1 < piles.size())
                ans = min(ans, help(idx + x, true, pref, piles, dp));
        return dp[idx][aliceTurn] = ans;
    }
    string stoneGameIII(vector<int> &stoneValue) {
        int n = stoneValue.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + stoneValue[i - 1];
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        int alice = help(0, true, pref, stoneValue, dp);
        int bob = pref.back() - alice;
        if (alice > bob)
            return "Alice";
        else if (alice < bob)
            return "Bob";
        return "Tie";
    }
};