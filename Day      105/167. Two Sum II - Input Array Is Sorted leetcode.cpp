class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        
        int i=0, n=nums.size(), j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==t)return {i+1, j+1};
            
             if(nums[i]+nums[j]<t)i++;
             if(nums[i]+nums[j]>t)j--;
            
            
            
        }
        return {i+1, j+1};
    }
};
