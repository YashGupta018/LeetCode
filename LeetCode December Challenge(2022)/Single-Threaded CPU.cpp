class Solution {
    typedef pair<int, int> T;
public:
    vector<int> getOrder(vector<vector<int>>& A) {
        priority_queue<T, vector<T>, greater<>> pq;
        long N = A.size(), time = 0, i = 0; 
        for (int i = 0; i < N; ++i) A[i].push_back(i);
        sort(begin(A), end(A));
        vector<int> ans;
        while (i < N || pq.size()) {
            if (pq.empty()) {
                time = max(time, (long)A[i][0]);
            }
            while (i < N && time >= A[i][0]) {
                pq.emplace(A[i][1], A[i][2]);
                ++i;
            }
            auto [pro, index] = pq.top();
            pq.pop();
            time += pro;
            ans.push_back(index);
        }
        return ans;
    }
};