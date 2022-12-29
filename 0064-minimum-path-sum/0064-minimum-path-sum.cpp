class Solution {
public:
    int n,m;
    int minPathSum(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
      
        
        for(int i=1; i<n;i++)grid[i][0] += grid[i-1][0];
        for(int j=1; j<m; j++)grid[0][j]+= grid[0][j-1];
        
        for(int i=1;i<n;i++)
        {
            for(int j=1; j<m ;j++)
            {
                grid[i][j]+= min(grid[i-1][j], grid[i][j-1]);
            }
            
        }
        return grid[n-1][m-1];
        
       
    }
    int go(int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int left=1e9, up=1e9;
        if(i-1>=0)left= go(i-1, j,grid,dp);
        if(j-1>=0)up= go(i,j-1, grid,dp);
        return dp[i][j]= grid[i][j]+ min(left,up);
    }
};