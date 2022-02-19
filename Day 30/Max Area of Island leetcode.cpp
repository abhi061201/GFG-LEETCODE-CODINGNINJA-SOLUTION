class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m= grid[0].size();
        
        int ans=0;
      
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(grid[i][j]==1){
                    int temp=1;
                    bfs(grid,temp,i,j);
                    ans= max(ans,temp);
                }
            }
        }
        return ans;
        
    }
    void bfs(vector<vector<int>>& grid,int &temp,int i,int j){
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;
         int dr[4][2]= {{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int curi= q.front().first;
            int curj= q.front().second;
            q.pop();
                for(int k=0 ;k<4 ;k++){
                    int dx= dr[k][0];
                    int dy= dr[k][1];
                    int nbrx=curi+dx;
                    int nbry= curj+dy;
                    
                    if(nbrx>=0 && nbrx<n && nbry>=0 && nbry<m&& grid[nbrx][nbry]==1){
                        temp++;
                        grid[nbrx][nbry]=0;
                        q.push({nbrx,nbry});
                    }
                    
                }
        }
    }
};
