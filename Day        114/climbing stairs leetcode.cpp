class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return go(n,dp);
    }
    int go(int n, vector<int>&dp){
        if(dp[n]!=-1)return dp[n];
        if(n<3)return n;
        
        return dp[n]=go(n-1,dp)+go(n-2,dp);
    }
};
