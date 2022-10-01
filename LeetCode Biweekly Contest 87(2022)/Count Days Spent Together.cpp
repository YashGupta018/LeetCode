class Solution {
public:
    int countDaysTogether(string aa, string bb, string cc, string dd) {
        vector<int>month = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string start = max(aa, cc), end = min(bb, dd);
        if(start <= end){
            int p = stoi(start.substr(0,2)), r =stoi(start.substr(3,2));
            int q = stoi(end.substr(0,2)), s =stoi(end.substr(3,2));
            if(q == p) 
                return s - r + 1;
            int days = month[p] - r;
            for(int t = p + 1; t < q; t++){
                days += month[t];
            }
            days += s + 1;
            return days;
        }
        return 0;
    }
};