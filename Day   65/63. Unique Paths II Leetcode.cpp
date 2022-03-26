class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return go(0,0,n,m, grid,dp);
    }
    
    int go(int i, int j, int n , int m ,vector<vector<int>>&grid,vector<vector<int>>&dp){
         if(grid[i][j]==1)return 0;
        if(i==n-1 and j==m-1)return 1;
       
        int path=0;
        if(dp[i][j]!=-1)return dp[i][j];
        int dr[2][2]= {{1,0},{0,1}};
        
        for(int k=0 ; k<2 ; k++){
            int curi= i+dr[k][0];
            int curj= j+dr[k][1];
            
            if(curi>=0 && curj>=0  and curi<n && curj <m && grid[i][j]==0){
                path+=go(curi, curj, n, m, grid,dp);
            }
        }
        return dp[i][j]= path;
    }
};
