class Solution {
public:
    int parent[201];
    int findCircleNum(vector<vector<int>>& M) {
        int i, j, groups = 0, n = M.size();
        make_set(n); 
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                if(M[i][j])
                    union_sets(i, j);
            }
        }
        for(i = 0; i < n; i++) {
            if(i == parent[i])
                groups++;
        }   
        return groups;
    }
private:
    void make_set(int n) {
        for(int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
};