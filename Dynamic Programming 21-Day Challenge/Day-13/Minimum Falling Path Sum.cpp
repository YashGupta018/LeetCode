class Solution {
    public:
    int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if(r == matrix.size()-1 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
        if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
        if(dp[r][c] != INT_MAX) return dp[r][c];
        return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r+1, c-1, dp), minFallingPathSumHelper(matrix, r+1, c, dp)), minFallingPathSumHelper(matrix, r+1, c+1, dp));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
        int ans = INT_MAX;
        for(int c=0; c < cols; c++) {
            ans = min(ans, minFallingPathSumHelper(matrix, 0, c, dp));
        }
        return ans;
    }
};