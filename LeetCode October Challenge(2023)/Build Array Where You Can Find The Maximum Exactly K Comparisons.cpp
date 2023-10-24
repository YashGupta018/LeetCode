class Solution {
public:
   long long dp[51][102][102];
   int mod=1e9+7;
   
   long long solve(int m, int k, int c, int n, int mx, int id) {
         if (c == n) {
             if (id == k) {
                 return 1;
             }
             return 0;
         }
         
         if (dp[c][mx+1][id] != -1)
             return dp[c][mx+1][id];
         
         long long ans = 0;
         
         for (int i = 1; i <= m; i++) {
             int c1 = mx;
             int c2 = id;
             
             if (mx < i) {
                 c1 = i;
                 c2 = id + 1;
             }
             
             ans = (ans + solve(m, k, c+1, n, c1, c2)) % mod;
         }
         
         return dp[c][mx+1][id] = (ans) % mod;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(m, k, 0, n, -1, 0);
    }
};