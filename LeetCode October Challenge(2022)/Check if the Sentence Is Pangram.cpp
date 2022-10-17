class Solution {
public:
    bool checkIfPangram(string sentence) {
    int cnt[26] = {}, total = 0;
    for (auto ch: sentence)
        if (++cnt[ch - 'a'] == 1)
            total++;
    return total == 26;
    }
};