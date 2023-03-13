class MyCalendar {
    map<int, int> mp;
public:  
    bool book(int start, int end) {
        auto itr = mp.upper_bound(start);
        if(itr == mp.end() || end<= itr->second) {
            mp[end]=start;
            return true;
        } 
        else  return false;
    }
};