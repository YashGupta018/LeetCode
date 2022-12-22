class Solution {
public:
    int helper(string x, string y) {
        int m = x.size();
        int n = y.size();
        int dp[m+1][n+1];
        for(int i = 0; i<=m; i++) {
            dp[i][0]=0;
        }
        for(int i = 0; i<=n; i++) {
            dp[0][i]=0;
        }
        for(int i = 1; i<=m; i++) {
            for(int j = 1; j<=n; j++) {
                if(x[i-1]==y[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string smaller, string larger) {

        int x  = helper(smaller,larger);
        if(x == smaller.size()) {
            return true;
        }
        return false;      
    }
};