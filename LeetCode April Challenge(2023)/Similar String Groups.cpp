class UnionFind {
public:
    vector<int> parent, rank;
    int count;
    UnionFind(int n) : parent(n), rank(n), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
        count--;
        return true;
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    uf.union_(i, j);
                }
            }
        }
        return uf.count;
    }
    bool isSimilar(string& s1, string& s2) {
        if (s1 == s2) {
            return true;
        }
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 2) {
                    return false;
                }
            }
        }
        return diff == 2;
    }
};