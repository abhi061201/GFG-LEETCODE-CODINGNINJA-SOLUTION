class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        int count=0, st=INT_MIN, en= INT_MIN;
        for(auto it: in)
        {
            if(en<= it[0]){
                st= it[0];
                en= it[1];
            }
            else if(en<=it[1])
            {
                count++;
            }
            else if(en>it[1])
            {
                count++;
                st=it[0];
                en= it[1];
            }
            
        }
        return count;
    }
    bool overlap(int a1, int b1, int a2, int b2)
    {
        
        if(b1<=a2)return 0;
        if(b2<= a1)return 0;
        
        return 1;
        
    }
};