class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        if( s == "") { return 0; }
        std::map<char, int> charactersOfSubstr;       
        int longest = 0;
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if ( charactersOfSubstr.find(s[i]) != charactersOfSubstr.end() ) {
                charactersOfSubstr.find(s[i])->second++;
            }
            else {
                charactersOfSubstr.insert(pair<char, int>(s[i], 1));
            }
            while ( charactersOfSubstr.find(s[i])->second > 1 ) {
                charactersOfSubstr.find(s[j])->second--;
                ++j;
            }
            longest = longest >= i - j + 1 ? longest : i - j + 1;
        }
        return longest;
    }
};