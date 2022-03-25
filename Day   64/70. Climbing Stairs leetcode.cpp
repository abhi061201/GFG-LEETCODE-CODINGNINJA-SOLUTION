class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return go(n, dp);
        
    }
    int go(int n, vector<int>&dp){
        
       if(n<=2)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=go(n-1, dp)+ go(n-2,dp);
        
    }
};
