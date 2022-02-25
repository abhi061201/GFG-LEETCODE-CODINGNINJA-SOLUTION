class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n= cost.size();
        vector<int> dp(n,-1);
        return go(cost,n-1,dp);
    }
    int go(vector<int>cost,int n,  vector<int>& dp){
        
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=cost[n] +min(go(cost,n-1,dp),go(cost,n-2,dp));
        
        
    }
};
