class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //for left to right
        int n= nums.size();
        int maxi= nums[0], curpro=1;
        for(int i=0; i<n; i++)
        {
            if(curpro==0){
                curpro=1;
            }
            curpro*=nums[i];
            
            maxi= max(maxi, curpro);
        }
        curpro=1;
        for(int i=n-1; i>=0; i--)
        {
            if(curpro==0){
                curpro=1;
            }
            curpro*=nums[i];
            
            maxi= max(maxi, curpro);
        }
        
        return maxi;
    }
};
