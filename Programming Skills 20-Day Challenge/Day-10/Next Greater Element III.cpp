class Solution {
    public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (s.length() == 1) {
            return -1;
        }
        int i = s.length() - 2;
        for (; i >= 0 && s[i] >= s[i + 1]; i--) { }
        if (i == -1) {
            return -1;
        }
        reverse(s.begin() + i + 1, s.end());
        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                break;
            }
        }
        long next = stol(s);
        return next == n || next > INT_MAX ? -1 : next;
    }
};