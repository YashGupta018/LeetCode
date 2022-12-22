class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int n=x.size(),m=y.size();
        string s;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int i=n,j=m;
        while(i>0 && j>0) {
            if(x[i-1]==y[j-1]) {
                s+=x[i-1];
                i--;j--;
            }
            else {
                if(dp[i][j-1]>dp[i-1][j])j--;
                else i--;
            }
        }
        reverse (s.begin(),s.end());
        cout<<s;
        return dp[n][m];
    }
};