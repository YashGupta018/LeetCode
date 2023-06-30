class Solution {
public:
    bool isPossible(int mid, int n, int m, vector<vector<int>>& cells) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < mid; i++) {
            int row = cells[i][0] - 1;
            int col = cells[i][1] - 1;
            grid[row][col] = 1;
        }
        unordered_set<pair<int, int>, pair_hash> visited;
        deque<pair<int, int>> stack;
        for (int col = 0; col < m; col++) {
            if (grid[0][col] == 0) {
                stack.push_back({0, col});
            }
        }
        while (!stack.empty()) {
            pair<int, int> curr = stack.back();
            stack.pop_back();
            int row = curr.first;
            int col = curr.second;
            if (row == n - 1) {
                return true;
            }
            if (visited.count(curr)) {
                continue;
            }
            visited.insert(curr);
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (const auto& direction : directions) {
                int newRow = row + direction.first;
                int newCol = col + direction.second;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 0) {
                    stack.push_back({newRow, newCol});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = cells.size();
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(mid, row, col, cells)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
private:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
};