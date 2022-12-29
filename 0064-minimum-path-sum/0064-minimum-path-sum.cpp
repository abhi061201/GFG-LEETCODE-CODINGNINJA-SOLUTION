class Solution {
public:
    int n,m;
    int minPathSum(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return go(n-1, m-1, grid,dp);
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