class Solution {
public:
    int coinChange(vector<int>& coins, int t) {
        int n= coins.size();
        vector<vector<int>>dp(n+1, vector<int>(t+1, -1));
        int ans= go(coins,n-1, t,dp);
        if(ans==1e9 )ans=-1;
        return ans;
    }
    int go(vector<int>&arr, int i, int t, vector<vector<int>>&dp){
        
        // if(t==0)return 1;
        if(i==0){
            if(t%arr[0]==0)return t/arr[0];
            else return 1e9;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int pick=INT_MAX, npick=INT_MAX;
        npick= go(arr, i-1, t,dp);
        if(arr[i]<=t)pick= 1+go(arr, i, t-arr[i],dp);
        return dp[i][t]=min(pick, npick);
        
    }
    
    
};
