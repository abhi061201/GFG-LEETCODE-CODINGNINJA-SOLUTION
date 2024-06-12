class Solution {
public:
    void sortColors(vector<int>& nums) {
    int n= nums.size(), n_0=0,n_1=0,n_2=0;
        
        for(auto it: nums){
            if(it==0)n_0++;
            if(it==1)n_1++;
            if(it==2) n_2++;
        }
        int i=0;
        while(n_0>0){
            nums[i++]=0;
            n_0--;
        }
        while(n_1>0){
            nums[i++]=1;
            n_1--;
        }
        while(n_2>0){
            nums[i++]=2;
            n_2--;
        }
        
        
    }
};