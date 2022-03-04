#define  M 1000000007
class Solution {
public:
    int numRollsToTarget(int n, int k, int T) {
            vector<vector<int>>dp(n+1, vector<int>(T+1,-1));
        return go(n,k,T,dp);
        
    }
    int go(int n, int k ,int T,vector<vector<int>>&dp){
        
        if(n==0){
            return T==0 ? 1:0;
        }
        if(dp[n][T]!=-1)return dp[n][T];
        int ways= 0;
        for(int i=1 ;i<=k && T>=i;i++){
            ways= (ways%M+go(n-1,k,T-i,dp)%M)%M;
        }
        return dp[n][T]=ways%M;
        
        
    }
};
