class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int j = 0, N = A.size(), ans = 0;
        while (j < N) {
            int i = j, cnt = 0, first = -1, last = -1;
            while (j < N && A[j] != 0) {
                cnt += A[j] < 0;
                if (A[j] < 0) {
                    if (first == -1) first = j;
                    last = j;
                }
                ++j;
            }
            if (cnt % 2) ans = max({ ans, j - first - 1, last - i });
            else ans = max(ans, j - i);
            while (j < N && A[j] == 0) ++j;
        }
        return ans;
    }
};