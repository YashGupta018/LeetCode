class Solution {
    typedef array<int, 26> T;
    public:
    int largestPathValue(string C, vector<vector<int>>& E) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(C.size());
        for (auto &e : E) {
            G[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<T> cnt(C.size(), T{});
        queue<int> q;
        for (int i = 0; i < C.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                cnt[i][C[i] - 'a'] = 1;
            }
        }
        int ans = 0, seen = 0;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            int val = *max_element(begin(cnt[u]), end(cnt[u]));
            ans = max(ans, val);
            ++seen;
            for (int v : G[u]) {
                for (int i = 0; i < 26; ++i) {
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == C[v] - 'a'));
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return seen < C.size() ? -1 : ans;
    }
};
