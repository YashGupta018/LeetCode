class Solution {
public:
    int nn;
    long long mod = 1e9 + 7;
    long long dp[101][101];
    long long help(int num, int g, int k) {
        if (g == 0) {
            if (num == nn)
                return 1;
            else
                return 0;
        }
        if (dp[num][g] != -1)
            return dp[num][g];
        long long ans = 0;
        ans = (ans + ((nn - num) * help(num + 1, g - 1, k)) % mod) % mod;
        if (num >= k) {
            ans = (ans + ((num - k) * help(num, g - 1, k)) % mod) % mod;
        }
        return dp[num][g] = ans % mod;
    }
    int numMusicPlaylists(int n, int g, int k) {
        nn = n;
        memset(dp, -1, sizeof(dp));
        return help(0, g, k);
    }
};