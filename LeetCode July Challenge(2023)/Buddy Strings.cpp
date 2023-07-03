class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i, j, k, c = 0, a = 0;
        unordered_map<char, int> map;
        for (auto x : s)
            map[x]++;
        if (map.size() < s.size())
            a = 1;
        for (auto x : goal) {
            if (map.find(x) == map.end())
                return 0;
            if (map[x] == 1)
                map.erase(x);
            else
                map[x]--;
        }
        if (map.size() > 0)
            return 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] != goal[i])
                c++;
        }
        if (c == 2)
            return 1;
        if (a == 1 and c == 0)
            return 1;
        return 0;
    }
};