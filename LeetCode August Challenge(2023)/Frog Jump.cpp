class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recur(stones, mp, 0, 0, dp);
    }
    bool recur(vector<int>& stones, map<int, int> &mp, int i, int k, vector<vector<int>>& dp) {
        if(i == stones.size()-1) return dp[i][k] = 1;
        if(dp[i][k] != -1) return dp[i][k];
        for(int t=k-1; t<=k+1; t++) {
            if(t > 0 && mp.find(stones[i]+t) != mp.end()) {
                int ind = mp[stones[i]+t];
                if(recur(stones, mp, ind, t, dp)) return dp[i][k] = 1;
            }
        }
        return dp[i][k] = 0;
    }
};