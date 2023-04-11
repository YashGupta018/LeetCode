class Solution {
public:
    string removeStars(string s) {
        int i=0,j=0;
        for(i=0;i<s.size();i++) {
            if(s[i]=='*') {
                j--;
            }
            else {
                s[j++] = s[i];
            }
        }
        return s.substr(0,j);
    }
};