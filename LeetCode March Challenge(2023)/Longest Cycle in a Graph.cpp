class Solution {
    public:
    vector<vector<int>> graph;
    vector<int> visited;
    int ans = -1;
    void dfs(int node, int d, unordered_map<int, int>& mp) {        
        visited[node] = 1;
        mp[node] = d;
    for(int child: graph[node]) {
        if(visited[child] == 0) {
            dfs(child, d+1, mp);
        }
        else if(mp.count(child)) {
            ans = max(ans, d - mp[child] + 1);
        }
    }
}
int longestCycle(vector<int>& edges) {
    int n = edges.size();
    graph.resize(n);
    visited.resize(n, 0);
    for(int i=0; i<n; i++) {
        if(edges[i] != -1) graph[i].push_back(edges[i]);
    }
    for(int i=0; i<n; i++) {
        unordered_map<int, int> mp;
        dfs(i, 0, mp);
    }
    return ans;
    }
};