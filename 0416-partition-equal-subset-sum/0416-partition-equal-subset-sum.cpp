class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(),0), n= nums.size();
        
        if(sum&1)return 0;
        vector<vector<int>>dp(n+1, vector<int>(sum/2 +1, 0));
        for(int k=1; k<=sum/2; k++)dp[0][k]=0;
        dp[0][0]=1;
        for(int i=1; i<=n; i++)
        {
            dp[i][0]=1;
            for(int k=0 ; k<=sum/2 ; k++)
            {
                int take=0, n_take=0;
                if(nums[i-1]<= k)take= dp[i-1][k-nums[i-1]];
                n_take= dp[i-1][k];
                dp[i][k]=take|n_take;   
            }
        }
        
        return dp[n][sum/2];
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