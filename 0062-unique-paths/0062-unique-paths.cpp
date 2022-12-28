class Solution {
public:
    int uniquePaths(int m, int n) {
        int mod= 2*1e9;
        vector<vector<long long int>>dp(m+1, vector<long long int >(n+1, 1));
        // dp[0][0]=1;

        for(int i=1; i<m ; i++)
        {
            // dp[i][0]=1;
            for(int j=1; j<n; j++)
            {
                // dp[0][j]=1;
                int up = dp[i-1][j];
                int left = dp[i][j-1];
                dp[i][j]= (up%mod+left%mod)%mod;
            }
        }
        
        return dp[m-1][n-1];
    }
    int go(int i, int j,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up = go(i-1, j, dp);
        int left = go(i, j-1, dp);
        return dp[i][j]= up+left;
    }
};