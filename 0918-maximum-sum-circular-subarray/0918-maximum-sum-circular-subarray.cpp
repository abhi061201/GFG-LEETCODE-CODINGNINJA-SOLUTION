class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int>v= nums;
        for(auto it: nums)
            v.push_back(it);
        
        // getiing max subarray from normal array
        int maxi= kaden(nums);
        int sum= accumulate(nums.begin() , nums.end(),0);
        bool allnegative=1;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i]>0)allnegative=0;
            nums[i]*=-1;
        }
        if(allnegative)return maxi;
        int psuedomax= kaden(nums);
        maxi= max(maxi, sum+psuedomax);
        
        
        
        return maxi;
    }
    int kaden(vector<int>&nums)
    {
        int n= nums.size(), cursum=0, maxi=nums[0];
        for(int i=0; i<n ;i++)
        {
            cursum+= nums[i];
            maxi= max(maxi, cursum);
            if(cursum<0)cursum=0;
        }
        return maxi;
    }
};