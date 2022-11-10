class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size()+1][word2.size()+1];
        for(int k=0; k<=word1.size(); k++)
            dp[k][0] = k;
        for(int k=0; k<=word2.size(); k++)
            dp[0][k] = k;
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i][j - 1],
                    dp[i - 1][j], 
                    dp[i - 1][j - 1]});
            }
        }
        return dp[word1.size()][word2.size()];
    }
};