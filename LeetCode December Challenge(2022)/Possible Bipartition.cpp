#define WHITE 0
#define RED 1
#define BLUE 2

class Solution {
    public:
    bool possibleBipartition(int N, vector<vector<int>> &edges) {
        vector<vector<int>> adj(N + 1);
        vector<int> color(N + 1, WHITE);
        vector<bool> explored(N + 1, false);
        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i <= N; ++i) {
            cout << "adj[" << i << "]: ";
            for (int j = 0; j < adj[i].size(); ++j) {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (!explored[i]) {
                color[i] = RED;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    if (explored[u]) {
                        continue;
                    }
                    explored[u] = true;
                    for (auto v: adj[u]) {
                        if (color[v] == color[u]) {
                            return false;
                        }
                        if (color[u] == RED) {
                            color[v] = BLUE;
                        }
                        else {
                            color[v] = RED;
                        }
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};