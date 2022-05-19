class Solution {
public:
    int n,m;
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
         n= mat.size(),m= mat[0].size();
        
            vector<vector<int>>dp(n, vector<int>(m, -1));
        int ans=1;
        for(int i=0 ; i<n ; i++){
            
            for(int j=0 ; j<m ; j++){
               if(dp[i][j]==-1){
                   ans= max(ans, dfs(i,j,mat,dp));
               }
            }
        }
        
        return ans;
    }
    
    int dfs(int x,int y, vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(dp[x][y]!=-1)return dp[x][y];
        int path=1;
        int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0 ; k<4 ; k++){
            int i= x+dr[k][0];
            int j= y+dr[k][1];
            if(i>=0 && j>=0 && i<n && j<m && mat[x][y]<mat[i][j] ){
                path= max(path, 1+dfs(i,j,mat,dp));
            }
        }    
        return dp[x][y]=path;
        
    }
    
};
