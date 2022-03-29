class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxi=INT_MIN,curpro=1;
       // left subpart
        for(int i=0 ; i<n ; i++){
            curpro= curpro*nums[i];
            maxi= max(maxi, curpro);
            if(curpro==0)curpro=1;
        }
        curpro=1;
        for(int i=n-1; i>=0 ; i--){
            curpro *=nums[i];
            maxi= max(curpro, maxi);
            if(curpro==0)curpro=1;
            
        }
        return maxi;
        
    }
};
