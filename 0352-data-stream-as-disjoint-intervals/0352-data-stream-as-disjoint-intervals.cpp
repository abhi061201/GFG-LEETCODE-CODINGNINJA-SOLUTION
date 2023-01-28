class SummaryRanges {
public:
    vector<int>v;
    int maxi=0;
    SummaryRanges() {
        vector<int>temp(10002,0);
        v= temp;
    }
    
    void addNum(int value) {
        v[value]=1;
        maxi= max(maxi, value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        vector<int>temp;
        
        for(int i=0; i<=10000+1;i++)
        {
            if(v[i]==1)
            {
                while(v[i]==1)
                temp.push_back(i++);  
                i--;
            }
            else if(temp.size())
            {
                ans.push_back({temp.front(), temp.back()});
                temp={};
                
            }
           
        // return {};
            
            
        } return ans;
    }
    
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */