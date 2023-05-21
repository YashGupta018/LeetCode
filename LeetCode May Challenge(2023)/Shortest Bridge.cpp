class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    void change(vector<vector<int>> &grid, int x, int y) {
        q.push({x, y});
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = 2;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                change(grid, nx, ny);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool f = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    change(grid, i, j);
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        int ans = 0;
        while (q.size()) {
            int total = q.size();
            ans++;
            while (total--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        if (grid[nx][ny] == 1)
                            return ans - 1;
                        else if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};