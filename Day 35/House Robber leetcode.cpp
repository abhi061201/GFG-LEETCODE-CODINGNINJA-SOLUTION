class Solution {
public:
    int rob(vector<int>& v) {
        
        int n= v.size();
        vector<int>dp(n+1,-1);
       return fun(n-1,v,dp);   
    }
    int fun(int n, vector<int>&v,vector<int>&dp){
        if(n==0)return v[0];
        if(n==-1)return 0;
        if(dp[n]!=-1)return dp[n];
        int pick= v[n]+fun(n-2,v,dp);
        int non_pick= fun(n-1,v,dp);
        return dp[n]= max(pick, non_pick);
        
    }
};
