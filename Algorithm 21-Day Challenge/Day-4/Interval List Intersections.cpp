class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < size(A) && j < size(B)) {
            if(A[i][1] >= B[j][0] && A[i][0] <= B[j][1])
                ans.emplace_back(initializer_list<int>{ max(A[i][0], B[j][0]), min(A[i][1], B[j][1]) });
            A[i][1] < B[j][1] ? i++ : j++;
        }
        return ans;
    }
};