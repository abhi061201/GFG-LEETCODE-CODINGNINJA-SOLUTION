class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int neg=0;
        int o=0;
        for(auto it : nums){
            if(it<0)neg++;
            if(it==0)o=1;
        }
        if(o)return 0;
        if(neg%2!=0)return -1;
        return 1;
    }
};
