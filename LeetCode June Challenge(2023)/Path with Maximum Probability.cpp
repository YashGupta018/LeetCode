class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        vector<double> dist(n, INT_MIN);
        dist[start] = 1;
        while (!pq.empty()) {
            auto itr = pq.top();
            pq.pop();
            double dis = itr.first;
            int node = itr.second;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                double edW = it.second;
                if (dist[adjNode] < dis * edW) {
                    dist[adjNode] = dis * edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if (dist[end] == INT_MIN)
            return 0.00000;
        else
            return dist[end];
    }
};