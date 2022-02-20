class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int>dp(n+1,-1);
        return min(mcs(0,cost,n,dp),mcs(1,cost,n,dp));
    }
    int mcs(int i, vector<int>&cost,int n,vector<int>&dp){
        if(i==n-1||i==n-2)return cost[i];
        if(dp[i]!=-1)return dp[i];
        int l=mcs(i+1,cost,n,dp)+cost[i];
        int r= mcs(i+2,cost,n,dp)+cost[i];
       if(l==r)return dp[i]=r;
        else return dp[i]=min(l,r);
    }
};
