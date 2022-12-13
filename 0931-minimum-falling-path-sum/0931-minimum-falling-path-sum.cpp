class Solution {
public:
    int n;
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n= matrix.size();
        int ans= 1e9;
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0; i<n; i++)
        {
            ans= min(ans, go(0,i, matrix,dp));
        }
        return ans;
    }
    
    int go(int i, int j, vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int l=1e9, r=1e9, d=1e9;
        
        if(j-1>=0 && j-1 <n)l= matrix[i][j]+ go(i+1,j-1,matrix, dp);
        if(j>=0 && j <n)d= matrix[i][j]+ go(i+1,j,matrix, dp);
        if(j+1>=0 && j+1 <n)r= matrix[i][j]+ go(i+1,j+1,matrix, dp );
        return dp[i][j] = min({l,d,r});
        
    }
};