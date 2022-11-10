class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int j=2;j<n+1;j++){
            int maxi=0;
            for(int i=1;i<j;i++){
                maxi=max(maxi,max(dp[j-i]*i,i*(j-i)));
            }
            dp[j]=maxi;
        }
        return dp[n];
    }
};