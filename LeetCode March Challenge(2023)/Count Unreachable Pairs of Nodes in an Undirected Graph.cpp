class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<int> sizes(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                sizes[i] = dfs(i, adjList, visited);
            }
        }
        long long ans = 0;
        long long sum = 0;
        for (int size : sizes) {
            ans += sum * size;
            sum += size;
        }
        return ans;
    }
    int dfs(int u, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[u] = true;
        int size = 1;
        for (int v : adjList[u]) {
            if (!visited[v]) {
                size += dfs(v, adjList, visited);
            }
        }
        return size;
    }
};