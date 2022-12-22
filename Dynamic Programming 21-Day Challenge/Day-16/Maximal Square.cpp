class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int maxSqr = 0, rows = matrix.size() , column = matrix[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(column+1,0));
        for(int i=1;i<=rows;++i){
            for(int j=1;j<=column;++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+ 1;
                    maxSqr=max(maxSqr,dp[i][j]);
                }
            }
        }
        return maxSqr*maxSqr;
    }
};