class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return go(grid,m-1,n-1,dp);
        
    }
    int go(vector<vector<int>>& grid,int m,int n, vector<vector<int>>&dp){
        
        if(m==0 && n==0 )return grid[m][n];
        if(dp[m][n]!=-1)return dp[m][n];
        int left=INT_MAX;
        int right= INT_MAX;
        if(m>=0 && n-1>=0) left= grid[m][n]+go(grid,m,n-1,dp);
         if(m-1>=0 && n>=0) right= grid[m][n]+go(grid,m-1,n,dp);
        
        return dp[m][n]= min(left,right);
    }
};
