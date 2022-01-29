class Solution {
public:
   
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>&vis,int m,int n,char c){
        vis[x][y]=1;
        grid[x][y]=c;
        if(x+1<m && x+1>=0 && y<n && y>=0){
            if(!vis[x+1][y] && grid [x+1][y]=='1'){
                vis[x+1][y]=1;
                grid [x+1][y]=c;
                dfs(x+1,y,grid,vis,m,n,c);
            }
        }
        if(x-1<m && x-1>=0 && y<n && y>=0){
            if(!vis[x-1][y] && grid[x-1][y]=='1'){
                vis[x-1][y]=1;
                grid[x-1][y]=c;
                dfs(x-1,y,grid,vis,m,n,c);
            }
        }
        if(x<m && x>=0 && y+1<n && y+1>=0){
            if(!vis[x][y+1] && grid[x][y+1]=='1'){
                vis[x][y+1]=1;
                grid[x][y+1]=c;
                dfs(x,y+1,grid,vis,m,n,c);
            }
        }
        if(x<m && x>=0 && y-1<n && y-1>=0){
            if(!vis[x][y-1] && grid [x][y-1]=='1'){
                vis[x][y-1]=1;
                grid [x][y-1]=c;
                dfs(x,y-1,grid,vis,m,n,c);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m= grid.size();
        int n= grid[0].size();
        vector <vector <int>>vis(m, vector<int>(n,0));
        int count=0;
        char c='0';
        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    c++;
                    
                    
                    dfs(i,j,grid,vis,m,n,c);
                }
            }
        }  
         for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                cout<<grid[i][j]<<" , ";
                
                }
             cout<<"\n";
            }
        
        
        return count;
        
}
    };
