class Solution {
    public:
    int root[26];
    int get(int x) {
        return x == root[x] ? x : (root[x] = get(root[x]));
    }
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (x < y)  root[y] = x;
            else root[x] = y;
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans;
        for (int i = 0; i < 26; i++)  root[i] = i;
        for (int i = 0; i < s1.size(); i++) unite(s1[i] - 'a', s2[i] - 'a');
        for (auto x : baseStr) ans += (char)(get(x - 'a') + 'a');
        return ans;
    }
};