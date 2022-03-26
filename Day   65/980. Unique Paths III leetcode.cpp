class Solution {
public:
    vector<vector<int>>path;
     int validmoves=0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m= grid[0].size();
        int ans=0,count_obs=0;
       
        for(int i=0  ;i<n ;i++){
            for(int j=0 ;j<m ; j++ ){
                if(grid[i][j]!=-1)validmoves++;
            }
        }
        vector<vector<int>>vis(n+1, vector<int>(m+1, 0));
        for(int i=0  ;i<n ;i++){
            for(int j=0 ;j<m ; j++ ){
                if(grid[i][j]==1)ans= go(i, j, n, m , grid,vis);
            }
        }
        return ans;
        
    }
    
    int go(int i , int j , int n, int m ,vector<vector<int>>& grid, vector<vector<int>>&vis){
        
        
        if(grid[i][j]==2)return  path.size()==validmoves-1?1:0;
        if(grid[i][j]==-1 || vis[i][j])return 0;
        path.push_back({i,j});
        vis[i][j]=1;
        int dr[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
        int ans=0;
        for(int k=0 ;k<4 ;k++){
            int curi= i+dr[k][0];
            int curj= j+dr[k][1];
            
            // cout<<curi<<" , "<<curj<<"\n";
            if(curi>=0 && curj>=0 && curi<n && curj<m  ){
                ans+=go(curi, curj , n, m , grid,vis);
            }
        }
        path.pop_back();
        vis[i][j]=0;
        return ans;
    }
    
};
