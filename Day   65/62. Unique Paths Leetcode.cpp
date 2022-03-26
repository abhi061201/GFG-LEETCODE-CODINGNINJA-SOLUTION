class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return go(1,1,n, m,dp);
    }
    
    int go(int i, int j,int n , int m,vector<vector<int>>&dp){
        if(i==n && j==m)return 1;
        int path=0;
        if(dp[i][j]!=-1)return dp[i][j];
        int dr[2][2]= {{1,0},{0,1}};
        for(int k=0 ; k<2 ; k++){
            int curi= dr[k][0]+i;
            int curj= dr[k][1]+j;
            
            if(curi>=1 && curj>=1 && curi<=n && curj<=m){
                path+=go(curi, curj,n,m,dp);
            }
        }
        return dp[i][j]= path;
    }
};
