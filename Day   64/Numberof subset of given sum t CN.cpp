int go(vector<int>&num, int i, int t,vector<vector<int> >&dp){
    if(t==0)return 1;
    
    if(i==0){
        return t==num[0];
    }
    if(dp[i][t]!=-1)return dp[i][t];
    int nontake= go(num, i-1, t,dp);
    int take=0;
    if(t>=num[i])take=go(num, i-1,t-num[i],dp);
    return dp[i][t]=take+nontake;
}

int findWays(vector<int> &num, int tar)
{
    
    int n= num.size();
    vector<vector<int> >dp(n+1, vector<int>(tar+1,-1));
    return go(num ,n-1, tar,dp);
}
