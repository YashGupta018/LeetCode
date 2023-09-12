class Solution {
public:
    int minDeletions(string s) {
        array<int, 26> freq{};
        for (char c : s)
            ++freq[c - 'a'];
        sort(freq.begin(), freq.end(), greater<int>());
        int keep = 0, prev = INT_MAX;
        for (int f : freq) {
            if (!f || !prev)
                break;
            prev = min(f, prev - 1);
            keep += prev;
        }
        return s.size() - keep;
    }
};