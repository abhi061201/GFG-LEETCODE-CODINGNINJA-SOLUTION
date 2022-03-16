class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        vector<int>v;
        while(n!=0){
            
            v.push_back(n%2);
            n=n/2;
            
        }
        int count=0;
        for(auto it : v){
            if(it==1)count++;
        }
        
        return count;
    }
};
