class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n= grid.size();
        vector<vector<int>>vis(n, vector<int>(n,0));
        
        if(grid[0][0]==1)return -1;
        
        queue<pair<int,int>>q;
        int step=1,ans=1e9;
        int dr[8][2]={{-1,-1},{-1,1},{1,-1},{1,1},{0,1},{0,-1},{1,0},{-1,0}};
        q.push({0,0});
        while(!q.empty()){
            int size= q.size();
            for(int i=0 ; i<size ; i++){
                int curi=q.front().first;
                int curj=q.front().second;
                if(curi==curj&& curi==n-1){
                    ans=min(ans,step);
                }
                q.pop();
                for(int k=0 ; k<8 ; k++){
                    
                    int x=curi+dr[k][0];
                    int y=curj+dr[k][1];
                    if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0&& !vis[x][y]){
                        
                        vis[x][y]=1;
                        q.push({x,y});
                        
                    }
                    
                }
                
            }
            
            step++;
        }
        
        if(ans==1e9)return -1;
        return ans;
        
    }
};
