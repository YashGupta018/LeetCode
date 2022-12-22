class Solution {
    public:
    int longestPalindromeSubseqTabular(string& s) {
        if(s.empty())
            return 0;
        const int N = s.size();
        vector<vector<int> > dp(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++)
            dp[i][i] = 1;
        for(int l = 1; l < N; l++) {
            for(int i = 0; i < N - l; i++) {
                int j = i + l;
                if((j - i + 1) == 2) {
                    dp[i][j] = 1 + (s[i] == s[j]);
                }
                else {
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][N-1];
    }
    int longestPalindSubseqRec(vector<vector<int> >& dp, string& s, int i, int j) {
        if(i > j)
            return 0;
        if(i == j)
            return dp[i][j] = 1;
        if(dp[i][j] == -1) {
            if(s[i] == s[j])
                dp[i][j] = 2 + longestPalindSubseqRec(dp, s, i+1, j-1);
            else
                dp[i][j] = max(longestPalindSubseqRec(dp, s, i+1, j),
                longestPalindSubseqRec(dp, s, i, j-1));
        }
        return dp[i][j];
    }
    int longestPalindSubseqRecDriver(string& s) {
        if(s.empty())
                return 0;
        const int N = s.size();
        vector<vector<int> > dp(N, vector<int>(N, -1)); 
        return longestPalindSubseqRec(dp, s, 0, N-1);
    }
    int longestPalindromeSubseq(string s) {
        return longestPalindSubseqRecDriver(s);
    }
};