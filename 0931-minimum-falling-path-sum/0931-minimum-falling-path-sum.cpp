class Solution {
public:
    int n;
    int minFallingPathSum(vector<vector<int>>& mat) { 
        int ans=1e9;
        n= mat.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++)
        {
            ans= min(ans, go(0,i,mat, dp));      
        }
        return ans;      
    }
    int go(int i, int j, vector<vector<int>>&mat,vector<vector<int>>&dp)
    {
        if(i==mat.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=1e9, down=1e9, right=1e9;
        if(j-1 >=0 )left= go(i+1, j-1, mat,dp);
        down= go(i+1, j, mat,dp);
        if(j+1 < n)right= go(i+1, j+1, mat,dp);
        return dp[i][j]=mat[i][j]+ min({left, down, right});
    }
};