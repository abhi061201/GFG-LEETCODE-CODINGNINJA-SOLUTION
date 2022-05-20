class Solution {
public:
    int n,m;
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int path=0;
        n= grid.size();
        m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<int>>dp(n, vector<int>(m,-1));
        if(grid[0][0]==1)return 0;
        vis[0][0]=1;
        return dfs(0,0,grid,vis,dp);
        
        
        
    }
       int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(grid[i][j]==1)return 0 ;
        if(i==n-1 && j==m-1){
        
            return 1;
        }
           int ans=0;
        int dr[2][2]= {{0,1},{1,0}};
        for(int k=0; k<2 ; k++){
            int x= i+dr[k][0];
            int y= j+dr[k][1];
            
            if(x>=0&& y>=0 && x<n&& y<m && !vis[x][y]&& grid[x][y]!=1){
                vis[x][y]=1;
                ans+= dfs(x,y,grid,vis,dp);
                vis[x][y]=0;
            }
        }
        return dp[i][j]= ans;
    }
};
