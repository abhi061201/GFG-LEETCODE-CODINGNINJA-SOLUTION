class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return go(0,0,n-1,m-1,grid,dp);
        
    }
    int go(int i, int j,int n, int m ,vector<vector<int>>& grid, vector<vector<int>>&dp){
       
        if(i==n && j==m)return grid[n][m];
        if(dp[i][j]!=-1)return dp[i][j];
        int dow= INT_MAX, righ= INT_MAX;
        if(i+1<=n && j<=m) dow= grid[i][j]+ go(i+1, j, n, m , grid,dp);
        if(i<=n && j+1<=m) righ= grid[i][j]+ go(i, j+1, n , m , grid,dp);
        return dp[i][j]=min(dow, righ);
    }
};
