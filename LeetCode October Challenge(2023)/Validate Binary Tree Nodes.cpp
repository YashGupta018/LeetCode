class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        vector<vector<int>> graph(n);
        int edge = 0;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                graph[i].push_back(leftChild[i]);
                ++edge;
            }
            if (rightChild[i] != -1) {
                graph[i].push_back(rightChild[i]);
                ++edge;
            }
        }
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> indegree(n, 0);
        int ctr = 0;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                indegree[graph[i][j]]++;
            }
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] > 1) {
                return false;
            }
            if (indegree[i] == 0) {
                q.push(i);
                ctr++;
            }
        }
        while (!q.empty()) {
            int front = q.front();
            visited[front] = true;
            q.pop();
            for (int i : graph[front]) {
                indegree[i]--;
                if (!visited[i] && indegree[i] == 0) {
                    q.push(i);
                    ctr++;
                }
            }
        }
        if (ctr != n || edge != n - 1) {
            return false;
        }
        return true;
    }
};