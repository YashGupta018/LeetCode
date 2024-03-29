class Solution {
    public:
    int diagonalSum(vector<vector<int>>& m, int i = -1) {
        return accumulate(begin(m), end(m), 0, [&](int s, vector<int> &v) {
            return s + v[++i] + (i == v.size() - i - 1 ? 0 : v[v.size() - i - 1]);
        });
    }
};