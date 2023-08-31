class Solution {
public:
    int find(int u, vector<int> &parent) {
        if (u == parent[u])
            return u;
        return find(parent[u], parent);
    }
    void unionDSU(int u, int v, vector<int> &parent) {
        int p1 = find(u, parent);
        int p2 = find(v, parent);
        parent[p2] = p1;
    }
    int mst(int n, vector<vector<int>> &edges, vector<int> &includeEdge, vector<int> &excludeEdge) {
        vector<int> parent;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        int ans = 0;
        int count = 0;
        if (includeEdge.size() != 0) {
            unionDSU(includeEdge[0], includeEdge[1], parent);
            ans += includeEdge[2];
            count += 1;
        }
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            if (excludeEdge.size() != 0 && excludeEdge[0] == u && excludeEdge[1] == v && excludeEdge[2] == cost) {
                continue;
            }
            if (includeEdge.size() != 0 && includeEdge[0] == u && includeEdge[1] == v && includeEdge[2] == cost) {
                continue;
            }
            int p1 = find(u, parent);
            int p2 = find(v, parent);
            if (p1 != p2) {
                unionDSU(p1, p2, parent);
                ans += cost;
                count += 1;
            }
        }
        return count == n - 1 ? ans : INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        vector<vector<int>> originalEdges;
        for (auto edge : edges) {
            vector<int> originalEdge{edge[0], edge[1], edge[2]};
            originalEdges.push_back(originalEdge);
        }
        vector<vector<int>> result;
        vector<int> criticalEdges;
        vector<int> pseudoCriticalEdges;
        sort(edges.begin(), edges.end(),
        [](const vector<int> &x, const vector<int> &y)
        { return x[2] < y[2]; });
        vector<int> emptyVector;
        int originalCost = mst(n, edges, emptyVector, emptyVector);
        for (int i = 0; i < originalEdges.size(); i++) {
            int excludedCost = mst(n, edges, emptyVector, originalEdges[i]);
            int includedCost = mst(n, edges, originalEdges[i], emptyVector);
            if (excludedCost > originalCost) {
                criticalEdges.push_back(i);
            }
            else if (includedCost == originalCost) {
                pseudoCriticalEdges.push_back(i);
            }
        }
        result.push_back(criticalEdges);
        result.push_back(pseudoCriticalEdges);
        return result;
    }
};