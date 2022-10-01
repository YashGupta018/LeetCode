class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mf;
        for(auto j : nums) {
            if (j % 2 == 0) mf[j]++;
        }
        if(mf.size() == 0)
            return -1;
        int ele = 0;
        for(auto j : mf) ele = max(ele, j.second);
        vector<int> result;
        for(auto j : mf){
            if(j.second == ele)
                result.push_back(j.first);
        }
        sort(result.begin(), result.end());
        return result[0];
    }
};