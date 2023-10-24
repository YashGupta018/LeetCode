class MyHashMap {
public:
    vector<list<pair<int, int>>> v;
    int numElements;
    MyHashMap() {
        numElements = 0;
        v.resize(20);
    }
    
    void put(int key, int value) {

        if((double)(numElements / v.size()) > 0.5) grow();
        auto &list = v[key % v.size()];
        auto it = list.begin();
        while(it != list.end()){
            if(it->first == key) it->second = value;
            ++it;
        }
        
        if(it == list.end()){
            list.push_back(make_pair(key, value));
            ++numElements;
        }
    }
    
    int get(int key) {
        auto &list = v[key % v.size()];
        auto it = find_if(list.begin(), list.end(), [key](auto x){
           return x.first == key; 
        });
        return (it == list.end()) ? -1 : it->second;
    }
    
    void remove(int key) {
        auto &list = v[key%v.size()];
        list.remove_if([key, this](auto x) { 
            if(x.first == key){
                --numElements;
                return true;
            }
            return false;
        });
    }
    
    void grow(){
        vector<list<pair<int, int>>> v2;
        v2.resize(v.size());
        v.swap(v2);
        v.resize(v.size() * 2);
        numElements = 0;
        for(auto l : v2){
            auto it = l.begin();
            while(it != l.end()){
                put(it->first, it->second);
                ++it;
            }
        }
    }
    
};