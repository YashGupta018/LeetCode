class Solution {
    public:
    int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
        unordered_map<int, vector<int>> a_idx;
        vector<vector<int>> dp(A.size(), vector<int>(A.size()));
        for (auto i = 0; i < A.size(); ++i)
        a_idx[A[i]].push_back(i);
        for (auto i = 0; i < A.size(); ++i)
        for (int j = 0; j < i; j++) {
            auto prev = 2l * A[j] - A[i];
            if (prev < INT_MIN || prev > INT_MAX)
                continue;
                auto it = a_idx.find(prev);
            if (it != end(a_idx)) {
                for (auto k : it->second) {
                    if (k >= j)
                    break;
                    dp[i][j] += dp[j][k] + 1;
                }
            }
            res += dp[i][j];
        }
    return res;
    }
};