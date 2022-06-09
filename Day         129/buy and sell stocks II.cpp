class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return go(0, 1 ,prices,dp);
    }
    int go(int i ,int canbuy ,vector<int>&prices, vector<vector<int>>&dp){
        if(i==prices.size() )return 0;
        if(dp[i][canbuy]!=-1)return dp[i][canbuy];
            int profit = 0;
        
        if(canbuy ==1 ){
            profit= max (-prices[i]+ go(i+1 ,0,prices,dp),go(i+1, 1,prices,dp));
            
        }
        else {
            profit = max(prices[i] + go(i+1 ,1,prices,dp), go(i+1 ,0,prices,dp));
        }
        return dp[i][canbuy]= profit;
        
        
    }
};
