class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] || grid.back().back()) return -1;
        int res = 2, len = 1, maxX = grid[0].size() - 1, maxY = grid.size() - 1;
        queue<pair<int, int>> q;
        if (!maxX && !maxY) return 1 - (grid[0][0] << 1);
        q.push({0, 0});
        grid[0][0] = -1;
        while (len) {
            while (len--) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int x = max(0, cx - 1), lmtX = min(cx + 1, maxX); x <= lmtX; x++) {
                    for (int y = max(0, cy - 1), lmtY = min(cy + 1, maxY); y <= lmtY; y++) {
                        if (x == maxX && y == maxY) return res;
                        if (!grid[y][x]) {
                            grid[y][x] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
            res++;
            len = q.size();
        }
        return -1;
    }
};