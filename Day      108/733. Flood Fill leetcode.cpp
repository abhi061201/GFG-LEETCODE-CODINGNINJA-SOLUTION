class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int ri, int rj, int nc) {
        int n= grid.size(), m= grid[0].size();
        queue<pair<int,int>>q;
        q.push({ri,rj});
        int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            
            int curi= q.front().first;
            int curj= q.front().second;
            int temp= grid[curi][curj];
            q.pop();
            grid[curi][curj]=nc;
            for(int k=0 ; k<4 ; k++){
                int i= curi+dr[k][0];
                int j= curj+ dr[k][1];
                
                if(i>=0 && j>=0 && i<n &&j<m && grid[i][j]==temp && temp!=nc){
                    q.push({i,j});
                }
                
                
            }
            
            
        }
        return grid;
        
        
    }
};
