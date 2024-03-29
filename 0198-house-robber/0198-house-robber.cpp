class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return go(n-1, nums, dp);
    }
    int go(int i, vector<int>&nums,vector<int>&dp)
    {
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int l=0, r=0;
        l= nums[i]+ go(i-2, nums, dp);
        r= go(i-1, nums, dp);
        return dp[i]= max(l,r);
    }
};