class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return go(n-1,m-1,grid,dp);
        
    }
    int go(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return 1e9;
        if(i==0 && j==0)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=0;
        int up = go(i,j-1,grid,dp);
        int left= go(i-1,j, grid,dp);
        return dp[i][j]= grid[i][j]+ min({up,left});      
    }
};