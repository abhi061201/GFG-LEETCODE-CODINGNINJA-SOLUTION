class Solution {
public:
    int coinChange(vector<int>& coin, int amount) {
        int n= coin.size();
        sort (coin.begin(), coin.end());
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int ans=coin_help(n-1,coin,amount,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
    
    int coin_help(int i , vector<int>&coin, int t,vector<vector<int>>&dp ){
        if(dp[i][t]!=-1)return dp[i][t];
        if(i<0 || t<0 )return 1e9;
        if(i==0){
            if(t%coin[0]==0){
                return t/coin[0];
            }
            return 1e9;
            
        }
        
        int n_take=1e9, take=1e9;
        n_take= coin_help(i-1, coin, t,dp);
        if(t>=coin[i])take=1+coin_help(i,coin,t-coin[i],dp);
        
        return dp[i][t]= min(take, n_take);
        
        
    }
    
};
