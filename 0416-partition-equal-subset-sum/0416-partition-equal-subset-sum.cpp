class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(),0), n= nums.size();
        
        if(sum&1)return 0;
        vector<vector<int>>dp(n, vector<int>(sum/2 +1, -1));
        return go(n-1, nums, sum/2, dp);
    }
    int go(int i, vector<int>&nums, int k,vector<vector<int>>&dp)
    {
        if(i<0)return 0;
        
        if(k==0)return 1;
        if(dp[i][k]!=-1)return dp[i][k];
        int take=0, n_take=0;
        if(nums[i]<= k)take= go(i-1, nums, k-nums[i],dp);
        n_take= go(i-1, nums, k,dp);
        return dp[i][k]=take|n_take;
    }
};