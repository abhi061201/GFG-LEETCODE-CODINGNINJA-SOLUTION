class Solution {
public:
    int minMaxGame(vector<int>& nums) {
       int i=0;
        while(nums.size()!=1){
             vector<int>temp;
            int n= nums.size();
            for(int i=0 ; i<n/2 ; i++){
               if(i%2==0) temp.push_back(min(nums[2*i],nums[2*i+1]));
            else  temp.push_back(max(nums[2*i],nums[2*i+1]));
            }
            nums=temp;
        }
        return nums[0];
        
    }
};
