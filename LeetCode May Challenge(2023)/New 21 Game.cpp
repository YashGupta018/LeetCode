class Solution {
public:
    double new21Game(int n, int k, int mp) {
        if(k==0 || n>k+mp)return 1;
        vector<double>dp(n+1,0.0);
        dp[0]=1;
        double ans=0.0;
        double ps=1;
        for(int i=1;i<=n;i++) {
            dp[i] = ps/mp;
            if(i<k)ps += dp[i];
            else ans += ps/mp;
            if(i-mp>=0)ps -= dp[i-mp];
            }
        return ans;
    }
};