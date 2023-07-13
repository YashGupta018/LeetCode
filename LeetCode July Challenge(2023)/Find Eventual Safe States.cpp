class Solution {
public:
    bool DFS(int s, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVisited, vector<bool> &checkCycle) {
        visited[s] = dfsVisited[s] = true;
        for (auto it : graph[s]) {
            if (!visited[it]) {
                if (DFS(it, graph, visited, dfsVisited, checkCycle))
                    return checkCycle[s] = true;
            }
            else if (dfsVisited[it]) {
                return checkCycle[s] = true;
            }
        }
        dfsVisited[s] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int v = graph.size();
        vector<bool> visited(v), dfsVisited(v), checkCycle(v);
        vector<int> ans;
        for (int i = 0; i < v; i++) {
            if (!visited[i])
                DFS(i, graph, visited, dfsVisited, checkCycle);
        }
        for (int i = 0; i < v; i++) {
            if (!checkCycle[i])
                ans.push_back(i);
        }
        return ans;
    }
};