class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector <pair<int, string>> b;
        for(int a = 0; a < names.size(); a++){
            b.push_back({heights[a], names[a]});
        }
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        vector<string> result;
        for(auto a : b){
            result.push_back(a.second);
        }
        return result;
    }
};