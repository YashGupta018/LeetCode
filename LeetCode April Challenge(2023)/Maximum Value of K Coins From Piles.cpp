class Solution {
public:
    const int inf = 1e9;
    int dp[1001][2001];
    int help(int idx, int k, vector<vector<int>> &piles) {
        if (k == 0)
            return 0;
        if (idx == piles.size()) {
            if (k == 0)
                return 0;
            return -inf;
        }
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int ans = -inf;
        for (int i = 0; i < min(k, (int)piles[idx].size()); i++)
            ans = max(ans, piles[idx][i] + help(idx + 1, k - (i + 1), piles));
        return dp[idx][k] = max(ans, help(idx + 1, k, piles));
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        for (int i = 0; i < n; i++)
            for (int j = 1; j < piles[i].size(); j++)
                piles[i][j] += piles[i][j - 1];
        return help(0, k, piles);
    }
};