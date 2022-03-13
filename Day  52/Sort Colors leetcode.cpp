class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int c_0=0, c_1=0 , c_2=0;
        
        for(auto it : nums){
            
            if(it==0)c_0++;
            if(it==1)c_1++;
            if(it==2)c_2++;
            
        }
        int n= nums.size();
        int i=0;
        while(c_0--){
            nums[i]=0;
            i++;
        }
        while(c_1--){
            nums[i]=1;
            i++;
        }
        while(c_2--){
            nums[i]=2;
            i++;
        }
        
        
    }
};
