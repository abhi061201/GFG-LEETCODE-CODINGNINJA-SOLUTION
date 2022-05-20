class Solution {
public:
    int n,m;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         n= mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                }
            }
        }
        queue<pair<int, int>> q;
        for(int i=0 ; i<n ; i++ ){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int dr[4][2]= {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int i= q.front().first;
            int j= q.front().second;
            vis[i][j]=1;
            q.pop();
            for(int k=0 ; k<4 ; k++){
                int x= i+dr[k][0];
                int y= j+dr[k][1];
                
                if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]){
                    q.push({x,y});
                    dp[x][y]= min(dp[x][y], 1+dp[i][j]);
                }
            }
            
        }
       
    return dp;
    }
};
