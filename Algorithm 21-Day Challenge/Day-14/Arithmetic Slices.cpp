class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
    for (auto i = 2, j = 1; i < A.size(); ++i) {
        if (A[i] - A[i - 1] != A[j] - A[j - 1])
            j = i;
        res += i - j;
    }
    return res;
    }
};