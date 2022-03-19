class FreqStack {
public:
    map<int,vector<int>,greater<int>> stack;
    unordered_map<int,int> map;
    FreqStack() {
        
    }
    
    void push(int val) {
        map[val]++;
        stack[map[val]].push_back(val);
    }
    
    int pop() {
        
        auto x = stack.begin();
        int ans = x->second[x->second.size()-1];
        x->second.pop_back();
        if(x->second.size()==0)
        {
            stack.erase(x->first);
        }
        map[ans]--;
        return ans;
    }
};
