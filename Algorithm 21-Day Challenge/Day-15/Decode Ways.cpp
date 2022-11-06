class Solution {
    public:
    int numDecodings(string s) {
        if (!s.size() || s.front() == '0') return 0;
        int r1 = 1, r2 = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') r1 = 0;
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                r1 = r2 + r1;
                r2 = r1 - r2;
                }
            else {
                r2 = r1;
            }
        }
        return r1;
    }
};