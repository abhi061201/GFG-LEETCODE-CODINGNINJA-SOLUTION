class Solution {
public:
    int n;
    int jump(vector<int>& nums) {
      n= nums.size();
        vector<int>dp(n,-1);
        return go(0,nums,dp);
    }
    int go(int i, vector<int>&nums,vector<int>&dp)
    {
        if(i==nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=1e9;
        for(int j=1; j<=nums[i]&& i+j <n ; j++ )
        {
            ans= min(ans, 1+go(i+j, nums,dp));
        }
        return dp[i]=ans;
    }
};