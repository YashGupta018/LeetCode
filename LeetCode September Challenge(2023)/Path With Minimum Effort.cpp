class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        efforts[0][0] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [effort, x, y] = pq.top();
            pq.pop();
            if (x == m - 1 && y == n - 1)
                return effort;
            for (auto &dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nextEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if (efforts[nx][ny] > nextEffort) {
                        efforts[nx][ny] = nextEffort;
                        pq.push({nextEffort, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};