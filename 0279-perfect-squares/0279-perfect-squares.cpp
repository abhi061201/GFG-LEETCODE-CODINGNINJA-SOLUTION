class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return go(n,dp);
    }
    int go(int n,vector<int>&dp)
    {
        if(n<=3)return n;
        if(dp[n]!=-1)return dp[n];
        int t= sqrt(n);
        int mini= 1e9;
        for(int i=t; i>1; i--)
        {
            mini = min(mini, go(n%(i*i),dp) + n/(i*i));
        }
        return dp[n]=mini;
    }
};