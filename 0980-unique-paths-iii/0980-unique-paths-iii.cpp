class Solution {
public:
    int n, m;
    int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    int validmoves= 0;
    int pathlen=0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        
        int si, sj;
        for(int i=0 ;i<n; i++)
        {
            for(int j=0 ; j<m; j++)
            {
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
                if(grid[i][j]!=-1)validmoves++;
            }
        }
        return go(si, sj, grid);
    }
    int go(int i, int j,vector<vector<int>>& grid )
    {
        if(grid[i][j]==2)return pathlen==validmoves-1? 1:0;
        grid[i][j]=-1;
        pathlen+=1;
        int path=0;
        for(int k=0; k<4; k++)
        {
            int curi= i+dr[k][0];
            int curj= j+dr[k][1];
            if(curi>=0 && curi<n && curj>=0 && curj<m && grid[curi][curj]!=-1)
            {
               path+= go(curi, curj, grid); 
            }
        }
        pathlen-=1;
        grid[i][j]=0;
        return path;
        
    }
};