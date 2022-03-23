// Top down 
TC= O(N*target)
TC= O(N* target) + O(N)    

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
    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
    dp[0][0]=1;
    for(int i=1 ; i<=n ;i++)dp[i][0]=1;
    
    for(int i=1 ; i<=n ; i++){
        for(int target=1 ; target<=k ; target++){
            dp[i][target]= dp[i-1][target] ;
            if(target>=arr[i-1]){
                dp[i][target]= dp[i-1][target]|| dp[i-1][target-arr[i-1]];
            }
        }
    }
    return dp[n][k];
    
}

// bottom up 
// TC= O(N*Target)
// Sc = O(N*target)
