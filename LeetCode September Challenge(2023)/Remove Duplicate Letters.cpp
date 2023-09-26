class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnts;
        string ret;
        stack<char> stk;
        vector<bool> isVisited(26, false);
        for (char each : s) cnts[each] ++;
        for (int i = 0; i < s.size(); cnts[s[i]] --, ++ i) {
            if (isVisited[s[i] - 'a'] || (!stk.empty() && stk.top() == s[i])) continue;
            while (!stk.empty() && stk.top() > s[i] && cnts[stk.top()] > 0) {
                isVisited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(s[i]);
            isVisited[s[i] - 'a'] = true;
        }
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};