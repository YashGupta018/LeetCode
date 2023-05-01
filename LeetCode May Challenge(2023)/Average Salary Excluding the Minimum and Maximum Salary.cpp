class Solution {
public:
    double average(vector<int>& s) {
        sort(s.begin(),s.end());
        double sum=0;
        for(int i=1;i<s.size()-1;i++)
            sum=sum+double(s[i]);
        return sum/double(s.size()-2);
    }
};