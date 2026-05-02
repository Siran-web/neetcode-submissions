class MyHashSet {
public:
    vector<list<int>> vec;
    int size;
public:
    MyHashSet() { 
        size = 100;
        vec.resize(size); 
    }
    
    int hash(int key){
        return key % size;
    }

    list<int> :: iterator search(int key){
        int i = hash(key);
        return find(vec[i].begin() , vec[i].end() , key);
    }

    void add(int key) {
        int i = hash(key);
        if(contains(key)) return;
        vec[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = hash(key);
        vec[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        if(search(key) != vec[i].end())
            return true;
        return false;    
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */