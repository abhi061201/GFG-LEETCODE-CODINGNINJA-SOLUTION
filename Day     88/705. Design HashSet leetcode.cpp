class MyHashSet {
public:
    vector<int>v;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool flag=0;
        for(auto it :v){
            if(it==key)flag=1;
        }
        if(!flag)v.push_back(key);
    }
    
    void remove(int key) {
        for(auto it = v.begin(); it<v.end(); it++){
            int x= it-v.begin();
            if(v[x]==key)v.erase(it);
        }
    }
    
    bool contains(int key) {
        for(auto it : v){
            if(it==key)return 1;
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
