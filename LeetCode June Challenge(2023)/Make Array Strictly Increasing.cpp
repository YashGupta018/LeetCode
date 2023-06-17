class Solution {
private:
    int check(int curr, int left, vector<int> &arr1, vector<int> &arr2, vector<unordered_map<int, int>> &dp) {
        if (curr == arr1.size())
            return 0;
        if (dp[curr].find(left) != dp[curr].end())
            return dp[curr][left];
        int exclude, include;
        if (arr1[curr] > left)
            exclude = check(curr + 1, arr1[curr], arr1, arr2, dp);
        else
            exclude = INT_MAX;
        int rep = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();
        if (rep == arr2.size())
            include = INT_MAX;
        else
            include = check(curr + 1, arr2[rep], arr1, arr2, dp);
        if (include == INT_MAX)
            dp[curr][left] = exclude;
        else
            dp[curr][left] = min(exclude, include + 1);
        return dp[curr][left];
    }
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        sort(arr2.begin(), arr2.end());
        vector<unordered_map<int, int>> dp(2001);
        int val = check(0, INT_MIN, arr1, arr2, dp);
        if (val == INT_MAX)
            return -1;
        return val;
    }
};