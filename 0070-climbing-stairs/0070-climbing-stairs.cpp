class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return go(n, dp);
    }
    int go(int n, vector<int>&dp)
    {
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int one=0, two=0;
        one = go(n-1,dp);
        two= go(n-2,dp);
        return dp[n]=one+two;
    }
};