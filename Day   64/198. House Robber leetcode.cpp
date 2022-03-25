class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1, -1);
        return go(nums, n-1,dp);
    }
    
    int go(vector<int>&nums,int i, vector<int>&dp ){
        
        
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int nhichuraya= go(nums, i-1,dp);
        int churaya= nums[i]+ go(nums, i-2,dp);
        
        return dp[i]=max(churaya, nhichuraya);
        
    }
};
