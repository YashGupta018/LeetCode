class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        std::unordered_map<int, int> dp;
        dp[0] = 0;
        for (int x : rods) {
            unordered_map<int, int> nxt = dp;
            for (const auto& [d, y] : dp) {
                nxt[d + x] = max(nxt[d + x], y);
                nxt[abs(d - x)] = max(nxt[abs(d - x)],y + min(d, x));
            }
            dp = nxt;
        }
        return dp[0];
    }
};