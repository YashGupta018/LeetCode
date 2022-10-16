class Solution {
public:
    int dp[12][305];
    vector<int> arr;
    int maxquery(int i,int j) {
        int maxi = -1;
        for (int k = i; k <= j; k++) maxi = max(maxi,arr[k]);
        return maxi;
    }
    int minDifficulty(vector<int>& arr, int day) {
        this->arr = arr;
        int n = arr.size();
        if (n < day) return -1;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 305; j++) dp[i][j] = 1e6;
        }
        for (int i = 0; i < n; i++) dp[1][i] = maxquery(i,n-1);
        for (int d = 2; d <= day; d++) {
            for (int i = 0; i < n; i++) {
                if (n-i < d) {
                    dp[d][i] = 1e6;
                    continue;
                }
                for (int j = i; j < n; j++) {
                    dp[d][i] = min(dp[d][i], maxquery(i,j) + dp[d-1][j+1]);
                }
            }
        }
        return dp[day][0];
    }
};