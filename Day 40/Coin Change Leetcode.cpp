class Solution {
public:
    int coinChange(vector<int>& arr, int T) {
        
        int n= arr.size();
      
        vector<vector<int>>dp(n+1,vector<int>(T+1,1e5));
        for(int j=0 ;j<=n ;j++){
            dp[j][0]= 0;
        }
        for(int i=1 ;i<=n ;i++){
            
            for(int j=1 ;j<=T ;j++){
             
                if(j<arr[i-1])dp[i][j]=dp[i-1][j];
                else {
                    dp[i][j]=min( dp[i][j-arr[i-1]]+1,dp[i-1][j]);
                }
            }
        }
        if(dp[n][T]<1e4)
        return dp[n][T];
        else return -1;
    }
};
