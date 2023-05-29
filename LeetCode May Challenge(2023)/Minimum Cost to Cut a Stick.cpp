class Solution {
private:
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int minm = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j + 1] - cuts[i - 1] + helper(i, ind - 1, cuts, dp) + helper(ind + 1, j, cuts, dp);
            minm = min(minm, cost);
        }
        return dp[i][j] = minm;
    }
public:
    int minCost(int n, vector<int> &cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return helper(1, c, cuts, dp);
    }
};