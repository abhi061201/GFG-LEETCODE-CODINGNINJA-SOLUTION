class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0, zer=0;
        for(auto it: nums)
        {
            
            if(it<0)neg++;
            if(it==0)zer++;
        }
        
        if(zer>0)return 0;
        if(neg%2==1)return -1;
        return 1;
    }
};