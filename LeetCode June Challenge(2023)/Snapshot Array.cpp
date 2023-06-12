class SnapshotArray {
public:
    vector<map<int,int>>A;
    int s_id = 0;
    SnapshotArray(int length) {
        A.resize(length);
        for(int i = 0; i < length; i++)
            A[i][0] = 0;
    }
    void set(int index, int val) {
        A[index][s_id] = val;
    }
    int snap() {
        s_id++;
        return  s_id - 1;
    }
    int get(int index, int snap_id) {
        if(A[index].find(snap_id) == A[index].end()) {
            auto it = --A[index].lower_bound(snap_id);
            return it->second;
        }
        return A[index][snap_id];
    }
};