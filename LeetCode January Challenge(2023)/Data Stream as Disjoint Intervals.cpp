class SummaryRanges {
public:
    set<int> nums;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int start = *nums.begin();
        int end = *nums.begin();
        for (auto it = ++nums.begin(); it != nums.end(); it++) {
            int val = *it;
            if (val - end == 1) {
                end = val;
            }
            else {
                intervals.push_back({start, end});
                start = end = val;
            }
        }
        intervals.push_back({start, end});
        return intervals;
        
    }
};