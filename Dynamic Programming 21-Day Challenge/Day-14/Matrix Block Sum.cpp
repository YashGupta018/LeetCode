class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        vector<vector<int> > dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                int m=matrix.size();
                int n=matrix[i].size();
                int r1=max(0,i-k)+1; 
                int c1=max(0,j-k)+1;
                int r2= min(i+k+1,m);
                int c2= min(j+k+1,n);
                ans[i][j]=dp[r2][c2]+dp[r1-1][c1-1]-dp[r1-1][c2]-dp[r2][c1-1];
            }
        }
        return ans;
    }
};