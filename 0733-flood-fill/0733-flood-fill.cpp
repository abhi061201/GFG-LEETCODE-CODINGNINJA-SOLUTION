class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
        int n= grid.size(), m= grid[0].size(), time=0;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int prev_color= grid[sr][sc];
        if(prev_color==color)return grid;
        while(!q.empty())
        {        
            int i= q.front().first;
            int j= q.front().second;
            grid[i][j]= color;
            q.pop();
            for(int k=0; k<4; k++)
            {
                int x= i+dr[k][0];
                int y= j+dr[k][1];
                
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==prev_color)
                {                      
                    grid[x][y]=color;
                    q.push({x,y});
                }
            }
        }
        
        
        
        return grid;
    }
};