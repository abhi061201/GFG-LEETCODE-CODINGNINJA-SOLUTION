class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return go(n,dp);
    }
    int go(int i, vector<int>&dp)
    {
        if(i<0)return 0;
        if(i==0)return 1;
        if(dp[i]!=-1)return dp[i];
        int one= go(i-1,dp);
        int two= go(i-2,dp);
        return dp[i]=one+two;
    }
};