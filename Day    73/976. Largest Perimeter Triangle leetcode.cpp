class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int i=nums.size()-1;
        int sum=0;
        while(i>=2){
      if(nums[i]+nums[i-1]>nums[i-2] &&nums[i]+nums[i-2]>nums[i-1] && nums[i-2]+nums[i-1]>nums[i] )
    {
                sum=nums[i]+nums[i-1 ]+ nums[i-2];
          break;
            }
            i--;
        }
        
        return sum;
        
    }
};
