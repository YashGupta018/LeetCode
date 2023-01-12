class Solution {
public:
    void dfs (int node, int par, vector<vector<int>> &g, vector<vector<int>> &dp, vector<int> &ans, string &labels) {
        dp[node][labels[node]-'a']++;
        for (auto &child: g[node]) {
            if (child != par) {
                dfs(child, node, g, dp, ans, labels);
                for (int i=0; i<27; i++) {
                    dp[node][i] += dp[child][i];
                }
            }
        }
        ans[node] = dp[node][labels[node]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for (int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector <vector<int>> dp(n, vector<int>(27, 0));
        vector<int> ans(n);
        dfs(0, -1, g, dp, ans, labels);
        return ans;
    }
};