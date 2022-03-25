class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        cost.push_back(0);
        vector<int>dp(n+1,-1);
        return go(n, cost, dp);
        
    }
    
    int go(int i, vector<int>&cost, vector<int>&dp){
        
        if(i==0)return cost[0];
        if(i==1)return cost[1];
        if(dp[i]!=-1)return dp[i];
        int step1= cost[i]+ go(i-1, cost,dp);
        int step2= cost[i]+ go(i-2, cost,dp);
        
        return dp[i]= min(step1, step2);
        
    }
};
