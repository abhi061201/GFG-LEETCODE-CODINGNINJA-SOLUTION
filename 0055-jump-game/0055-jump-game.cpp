class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return go(0, nums,dp);
    }
    int go(int i, vector<int>&nums,vector<int>&dp)
    {
        if(i>=nums.size()-1)return 1;
        int ans=0;
        if(dp[i]!=-1)return dp[i];
        for(int j=1; j<=nums[i] ; j++)
        {
            if(i+j<nums.size())ans= ans| go(i+j, nums,dp);
            if(ans==1)return dp[i]= 1;
        }
        return dp[i]= ans;
        
    }
};