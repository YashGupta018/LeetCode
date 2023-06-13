class Solution {
public:
    string mapping(vector<int> & row) {
        string ans="";
        for(int j:row)
            ans+=to_string(j)+"#";
        return ans;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        unordered_map<string,int> mp;
        for(int i=0; i<n;i++)
            mp[mapping(grid[i])]++;
        for(int i=0; i<n;i++){
            string ans="";
            for(int j=0; j<n;j++)
                ans+=to_string(grid[j][i])+"#";
            count+=mp[ans];
        }
        return count;
    }
};