class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        set<string> str;
        int n1 = s.size();
        int n2 = dictionary.size();
        for (int i = 0; i < n2; i++) {
            str.insert(dictionary[i]);
        }
        vector<int> dp(n1 + 1, 0);
        for (int i = 1; i <= n1; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = i; j >= 1; j--) {
                string temp = s.substr(j - 1, i - j + 1);
                if (str.count(temp)) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }
        return dp[n1];
    }
};