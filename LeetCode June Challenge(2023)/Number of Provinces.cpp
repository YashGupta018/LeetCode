class Solution {
public:
    void dfs(int s, int n, vector<vector<int>> &isConnected, vector<bool> &visited) {
        visited[s] = true;
        vector<int> adj;
        for (int i = 0; i < n; i++) {
            int x = isConnected[s][i];
            if (x == 1)
                adj.push_back(i);
        }
        for (auto x : adj) {
            if (!visited[x]) {
                dfs(x, n, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                ans++;
                dfs(i, n, isConnected, visited);
            }
        }
        return ans;
    }
};