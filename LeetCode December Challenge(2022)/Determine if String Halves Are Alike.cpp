class Solution {
    set<char> vwls = {'a','e','i','o','u','A','E','I','O','U'};
    int sign(int val) { return (0 < val) - (val < 0); }
    public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
            if (vwls.count(s[i]))
                cnt += sign(s.size() - 2*i-1);
        return cnt == 0;
    }
};