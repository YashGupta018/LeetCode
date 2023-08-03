class Solution {
public:
    vector<string> ans;
    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    void backtrack(int index, string& path, const string& digits) {
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }
        for (char c : keyPad[digits[index] - '0']) {
            path[index] = c;
            backtrack(index + 1, path, digits);
        }
    }
    vector<string> letterCombinations(const string& digits) {
        if (digits.empty()) return ans;
        string path = digits;
        backtrack(0, path, digits);
        return ans;
    }
};