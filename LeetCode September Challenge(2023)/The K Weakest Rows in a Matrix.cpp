class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for(int row = 0; row < matrix.size(); row++) {
            int soldierCount = findSoldierCount(matrix[row]);
            minHeap.push({soldierCount, row});
        }
        vector<int> weakestRows;
        while (k--) {
            weakestRows.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return weakestRows;
    }
    int findSoldierCount(vector<int> &row) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (row[mid] == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};