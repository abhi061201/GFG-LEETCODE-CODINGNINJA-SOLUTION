class Solution {
public:
    void sortColors(vector<int>& nums) {
     
        int n= nums.size();
        int c_0=0;
         int c_1=0;
         int c_2=0;
        for(auto it : nums){
            if(it==0)c_0++;
            if(it==1)c_1++;
            if(it==2)c_2++;
        }
        
        for(int i=0 ;i<c_0 ;i++){
            nums[i]=0;
        }
       
          for(int i=c_0 ;i<c_1+c_0 ;i++){
            nums[i]=1;
        }
          for(int i=c_1+c_0 ;i<c_2+c_0+c_1 ;i++){
            nums[i]=2;
        }
        
        
    }
};
