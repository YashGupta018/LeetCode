class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        for(int i=0;i<t.size();i++) {
            if(t[i]=="+") {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
                }
            else if(t[i]=="*") {
                long a=st.top();
                st.pop();
                long b=st.top();
                st.pop();
                st.push(b * a);
                }
            else if(t[i]=="-") {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
                }
            else if(t[i]=="/") {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
                }
            else {
                st.push(stoi(t[i]));
                }
            } 
        return st.top();
    }
};