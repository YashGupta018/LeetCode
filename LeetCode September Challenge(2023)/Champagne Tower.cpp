class Solution {
public:
    double champagneTower(int X, int row, int col) {
        vector<vector<double>> dp(101, vector<double>(101));
        dp[0][0] = X;
        for(int i=0; i<100; i++) {
            for(int j=0; j<=i; j++) {
                if(dp[i][j] >= 1) {
                    dp[i+1][j] += (dp[i][j] - 1)/2.0;
                    dp[i+1][j+1] += (dp[i][j] - 1)/2.0;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[row][col];
    }
};