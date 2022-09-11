class Solution {
public:
    int partitionString(string s) {
        map<char, int> a;
        int sol = 1;
        for(int j = 0; j < s.size(); j++){
            if(a.find(s[j]) == a.end())
                a[s[j]] += 1;
            else{
                sol += 1;
                a.clear();
                a[s[j]] += 1;
            }
        }
        return sol;
    }
};