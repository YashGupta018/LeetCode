class Solution {
public:
    int mod = pow(10, 9) + 7;
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int parent) {
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= parent) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int down  = helper(i + 1, j, grid, dp, grid[i][j]) % mod;
        int up    = helper(i - 1, j, grid, dp, grid[i][j]) % mod;
        int right = helper(i, j + 1, grid, dp, grid[i][j]) % mod;
        int left  = helper(i, j - 1, grid, dp, grid[i][j]) % mod;
        return dp[i][j] = (down + up + right + left + 1) % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] == -1) {
                    helper(i, j, grid, dp, -1);
                }
            }
        } 
        long long ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = (ans + dp[i][j]) % mod;
            }
        }
        return ans;
    }
};