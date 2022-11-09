class StockSpanner {
public:
    vector<int>v;
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int n= v.size();
        int ans=1;
        while(!st.empty() && st.top().first <= price)
        {
            ans+= st.top().second;
            st.pop();
        }
        st.push({price,ans});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */