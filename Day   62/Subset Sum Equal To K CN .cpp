bool go(vector<int> &arr, int i, int t,vector<vector<int>>&dp){
    if(t==0)return true;
    if(i==0)return t==arr[0];
    if(dp[i][t]!=-1)return dp[i][t];
    bool nontake= go(arr, i-1, t,dp);
    bool take= false;
    if(arr[i] <=t)take= go(arr, i-1, t-arr[i],dp);
    
    return dp[i][t]= take|| nontake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
    return go(arr, n-1, k,dp);
}
