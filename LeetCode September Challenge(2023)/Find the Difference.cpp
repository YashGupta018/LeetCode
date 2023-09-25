class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        char result = 0;
        for (char c : s + t) {
            result ^= c;
        }
        return result;
    }
};