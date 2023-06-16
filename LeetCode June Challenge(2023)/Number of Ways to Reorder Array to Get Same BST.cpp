class Solution {
public:
    vector<vector<long long>> ncr;
    long long mod = 1e9 + 7;
    long long ways(vector<int> &v, int n) {
        if (n <= 2)
            return 1;
        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (v[0] > v[i])
                left.push_back(v[i]);
            else
                right.push_back(v[i]);
        }
        long long ans_left = ways(left, left.size());
        long long ans_right = ways(right, right.size());
        long long ans = (((ncr[n - 1][left.size()] * ans_left) % mod) * ans_right) % mod;
        return ans;
    }
    int numOfWays(vector<int> &v) {
        int n = v.size();
        ncr.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            ncr[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
            }
        }
        return (ways(v, n) - 1) % mod;
    }
};