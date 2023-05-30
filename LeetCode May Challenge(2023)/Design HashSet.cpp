class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        v.resize(1000000 + 10, 0);
    }
    void add(int key) {
        v[key] = 1;
    }
    void remove(int key) {
        v[key] = 0;
    }
    bool contains(int key) {
        if (v[key])
            return true;
        else
            return false;
    }
};