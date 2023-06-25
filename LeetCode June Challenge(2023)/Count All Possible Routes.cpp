class Solution {
public:
    long dp[101][201], mod = 1e9 + 7;
    long solve(int idx, int fuel, int &finish, vector<int> &locations) {
        if (fuel < 0)
            return 0;
        if (dp[idx][fuel] != -1)
            return dp[idx][fuel];
        long ans = 0;
        for (int i = 0; i < locations.size(); i++)
            if (i != idx)
                ans = (ans + solve(i, fuel - abs(locations[idx] - locations[i]), finish, locations)) % mod;
        return dp[idx][fuel] = (idx == finish) + ans;
    }
    int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return solve(start, fuel, finish, locations);
    }
};