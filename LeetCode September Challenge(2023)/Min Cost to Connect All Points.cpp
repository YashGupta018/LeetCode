class Solution {
public:
    vector<int> parent;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int cost = 0;
        for(auto &edge : edges) {
            int dist = edge[0], x = edge[1], y = edge[2];
            if(find(x) != find(y)) {
                cost += dist;
                unionSet(x, y);
            }
        }
        return cost;
    }
    
    int find(int x) {
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unionSet(int x, int y) {
        parent[find(x)] = find(y);
    }
};
