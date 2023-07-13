class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> mpp;
        unordered_map<int, int> ind;
        vector<int> ans;
        queue<int> q;
        int n = prerequisites.size();
        for (int i = 0; i < n; ++i) {
            mpp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!ind.count(i)) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto &it : mpp[t]) {
                ind[it]--;
                if (ind[it] == 0) {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        if (ans.size() != numCourses)
            return false;
        return true;
    }
};