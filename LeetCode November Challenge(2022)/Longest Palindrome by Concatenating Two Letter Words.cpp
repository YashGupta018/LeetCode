class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        unordered_map<string,int> hm;
        for(string s:words) {
            string p = s;
            reverse(p.begin(),p.end());
            if(hm[p]>0) {
                res+= 4;
                hm[p]--;
            }
            else {
                hm[s]++;
            }
        }
        for(auto i:hm) {
            if(i.first[0]==i.first[1] && i.second>0) {
                return res+2;
            }
        }
        return res;
    }
};