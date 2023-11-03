class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        ans.reserve(2*n);
        int input=1;
        for(int x: target) {
            while (x> input) {
                ans.push_back("Push");
                ans.push_back("Pop");
                input++;
            }
            ans.push_back("Push");
            input++;  
        }
        return ans;
    }
};