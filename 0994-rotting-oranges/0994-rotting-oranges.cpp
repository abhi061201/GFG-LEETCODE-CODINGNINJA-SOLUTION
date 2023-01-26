class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int n= grid.size(), m= grid[0].size(), time=0;
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int N=q.size();
            
            while(N--)
            {
                int i= q.front().first;
                int j= q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int x= i+dr[k][0];
                    int y= j+dr[k][1];
                    // cout<<x<<" : "<<y<<endl;
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
                    {   
                        // cout<<"hi\n";
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            time++;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        return time==0?time: time-1;
    }
};