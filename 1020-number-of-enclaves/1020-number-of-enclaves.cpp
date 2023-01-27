class Solution {
public:
    int n, m;
    int dr[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        for(int i=0; i<n;i++)
        {
            if(grid[i][0]==1)dfs(i,0,grid);
            if(grid[i][m-1]==1)dfs(i,m-1,grid);
            
        }
        for(int j=0; j<m;j++)
        {
            if(grid[0][j]==1)dfs(0,j,grid);
            if(grid[n-1][j]==1)dfs(n-1,j,grid);
            
        }
        
        int count=0;
        for(int i=0; i<n ;i++)
        {
            for(int j=0; j<m ;j++)
            {
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
    void dfs(int i, int j, vector<vector<int>>&grid)
    {
        grid[i][j]=0;
        for(int k=0; k<4; k++)
        {
            int x= i+dr[k][0];
            int y = j+dr[k][1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)dfs(x,y,grid);
        }
        
    }
};