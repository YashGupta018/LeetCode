class NestedIterator {
public:
    vector<int> res;
    int idx=0;
    void flattenList(vector<NestedInteger> &nestedList) {
        for(auto x:nestedList) {
            if(x.isInteger()) {
                res.push_back(x.getInteger());
            }
            else {
                flattenList(x.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
    }
    int next() {
        return res[idx++];   
    }
    bool hasNext() {
        return idx<res.size();   
    }
};