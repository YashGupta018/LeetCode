class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto it : redEdges) {
            adj[it[0]].push_back({it[1], 1});
        }
        for(auto it : blueEdges) {
            adj[it[0]].push_back({it[1], 2});
        }
        vector<vector<int>> dist(n, vector<int> (3, 1e9));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int prev_color = q.front().second;
            q.pop();
            for(auto it : adj[node]) {
                int adj_node = it.first;
                int color = it.second;
                if(color == prev_color) continue;
                if(dist[adj_node][color] == 1e9) {
                    dist[adj_node][color] = dist[node][prev_color] + 1;
                    q.push({adj_node, color});
                }
            }
        } 
        vector<int> ans(n, 0);
        for(int i = 1; i < n; i++) {
            ans[i] = min(dist[i][1], dist[i][2]);
            if(ans[i] == 1e9) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};