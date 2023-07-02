class Solution {
public:
    void backtrack(vector<vector<int>>& requests, int index, vector<int>& count, int currCount, int& maxCount) {
        if (index == requests.size()) {
            for (int i = 0; i < count.size(); i++) {
                if (count[i] != 0) return;
            }
            maxCount = max(maxCount, currCount);
            return;
        }
        int from = requests[index][0];
        int to = requests[index][1];
        count[from]--;
        count[to]++;
        backtrack(requests, index + 1, count, currCount + 1, maxCount);
        count[from]++;
        count[to]--;
        backtrack(requests, index + 1, count, currCount, maxCount);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> count(n);
        int maxCount = 0;
        backtrack(requests, 0, count, 0, maxCount);
        return maxCount;
    }
};