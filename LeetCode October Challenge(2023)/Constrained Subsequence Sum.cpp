class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int total = num + (!q.empty() ? q.front().second : 0);
            res = max(res, total);
            while (!q.empty() && total >= q.back().second) {
                q.pop_back();
            }
            if (total > 0) {
                q.push_back(make_pair(i, total));
            }
            if (!q.empty() && q.front().first == i - k) {
                q.pop_front();
            }
        }
        return res;        
    }
};