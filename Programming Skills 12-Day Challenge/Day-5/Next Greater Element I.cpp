class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ans;
        stack<int> st;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num)
                st.pop();
            if (!st.empty())
                ans[num] = st.top();
            st.push(num);
        }
        vector<int> out;
        for (int num : nums1) {
            if (ans.count(num))
                out.push_back(ans[num]);
            else
                out.push_back(-1);
        }
        return out;
    }
};