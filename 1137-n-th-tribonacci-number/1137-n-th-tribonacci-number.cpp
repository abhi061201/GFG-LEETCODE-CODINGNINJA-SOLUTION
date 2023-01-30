#define ll long long int 
class Solution {
public:
    int tribonacci(int n) {
        
        vector<int>dp(n+1,-1);
        return go(n,dp);
    }
    int go(int n,vector<int>&dp)
    {
        if(n==0)return 0;
        if(n<3)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=go(n-1,dp)+go(n-2,dp)+go(n-3,dp);
    }
    
};