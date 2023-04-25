class SmallestInfiniteSet {
public:
    
    set<int>se;
    SmallestInfiniteSet() {
        for(int i=1; i<1001;i++)se.insert(i);
    }
    
    int popSmallest() {
        
        auto it= se.begin();
        int x= *it;
        se.erase(it);
        return x;
    }
    
    void addBack(int num) {
        se.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */