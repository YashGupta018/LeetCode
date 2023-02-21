class Solution {
    public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [](int a,int b){int x=__builtin_popcount(a),y=__builtin_popcount(b);return x==y ? a<=b : x<y ;});
        return arr;
    }
};