class Solution {
public:
    int n,m;
    int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans=0;
         n= grid.size(), m= grid[0].size();
       
        
      for(int i=0 ; i<n ; i++){
          for(int j=0 ; j<m ; j++){
              int maxi=0;
              if(grid[i][j]==1){
                  cout<<"HII\n";
                  bfs(i,j,grid,maxi);
                  
                  ans= max(maxi,ans);
              }
          }
      }
        return ans;
    }
    
    void bfs(int x,int y,vector<vector<int>>& grid , int &maxi){
        
        
        
        queue<pair<int,int>>q;
        q.push({x,y});
        grid[x][y]=0;
        while(!q.empty()){
            
            int curi= q.front().first;
            int curj= q.front().second;
            // cout<<curi<<" , "<<curj<<"\n";
            q.pop();
            maxi++;
            
            for(int k=0 ; k<4 ; k++){
                int i= curi+dr[k][0];
                int j= curj+dr[k][1];
                
                if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        
    }
    
};
