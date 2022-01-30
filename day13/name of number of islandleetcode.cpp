class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        int step=0;
        char c='1';
        
        vector <vector <int>> vis(m,vector <int>(n,0));
        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    
                    bfs(i,j,grid,vis,c);
                    step++;
                    c++;
                }
            }
        }
        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                cout<<grid[i][j]<<" , ";
                }
            cout<<"\n";
            }
      
        return step;
        
        
    }
    
    void  bfs(int i,int j,vector<vector<char>>&grid, vector <vector <int>> &vis,char c){
        
        int m=grid.size();
        int n= grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
       int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
             int x= q.front().first;
            int y= q.front().second;
            q.pop();
            if(!vis[x][y]){
            vis[x][y]=1;
            grid[x][y]=c;
            for(int k=0 ; k<4 ;k++){
                int dx= dr[k][0];
                int dy= dr[k][1];
                int nbrx= x+dx;
                int nbry = y + dy;
     if(nbrx>=0 && nbrx<m && nbry >=0 && nbry<n && grid[nbrx][nbry]=='1' && !vis[nbrx][nbry] )                     {
         q.push({nbrx,nbry});
         }
            }
           
            
            }
            
            
           
        }
        
        
    }
    
};

