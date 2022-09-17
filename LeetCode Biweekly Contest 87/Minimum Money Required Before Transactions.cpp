class Solution 
{
    public: 
    long long max(long long p, long long q) 
    {
        return (p>q?p:q);
    } 
    long long min(long long p, long long q) 
    {
        return (p<q?p:q);
    } 
    long long minimumMoney (vector<vector <int>>& t) 
    {
        long long r = 0; 
        for(auto s : t) 
            r = max(r, min(s[0], s[1])); 
        for(auto s : t) 
            r += max(0, s[0] - s[1]); 
        return r;
    }
};