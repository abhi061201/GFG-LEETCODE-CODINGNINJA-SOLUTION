class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0, n= nums.size();
        
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1])count++;
        }
        if(count==1)return nums[0]>=nums[n-1];
        return count==0;
    }
};