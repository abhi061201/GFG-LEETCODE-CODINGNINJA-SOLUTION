class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mt) {
        
        int n= mt.size();
        int m= mt[0].size();
        int ans=1;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(dp[i][j]==-1)
               ans= max(ans, dfs(i,j,m,n, mt,dp)); 
            }
        }
        
        return ans;
        
    }
    int dfs(int i, int j, int m ,int n,vector<vector<int>>& mt,  vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        int path=1;
        int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
      
        for(int k=0 ;k<4 ;k++){
            int nbri= i+dr[k][0];
            int nbrj= j+dr[k][1];
            if(nbri>=0 && nbrj>=0 &&nbri<n && nbrj<m &&  mt[nbri][nbrj]>mt[i][j] ){
                path= max(path, 1+dfs(nbri, nbrj,m,n, mt,dp));
            }
        }
        return dp[i][j]= path;
        
    }
};
