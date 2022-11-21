class Solution {
public:
    int n, m;
    int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    set<pair<int,int>>se;
    int nearestExit(vector<vector<char>>& maze, vector<int>& en) {
         n= maze.size();
         m= maze[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m; j++)
            {
                if(maze[i][j]=='.' && (i==0 || i==n-1|| j==0 || j==m-1)){
                    if(i==en[0] && j==en[1])continue;
                    se.insert({i,j});
                    // cout<<i<<" , "<<j<<"\n";
                }
            }
        }
        return go(en[0], en[1], maze);
        
    }
    int go(int i, int j,vector<vector<char>>& maze )
    {
        int step=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        maze[i][j] = '+';
        while(!q.empty())
        {
            int si= q.size();
            for(int l=0; l<si ;l++)
            {
                // cout<<l<<" \n";
                int curi= q.front().first;
                int curj= q.front().second;
                q.pop();
                if(se.find({curi,curj})!= se.end())return step;
                for(int k=0; k<4; k++)
                {
                    int x= curi+dr[k][0];
                    int y= curj+dr[k][1];
                    if(isValid(x,y) && maze[x][y]=='.')
                    {
                        maze[x][y]='+';
                        q.push({x,y});
                    }
                }
            }
            step++;
        }
        return -1;
    }
    
    bool isValid(int i, int j)
    {
        if(i>=0 && i<n && j>=0 && j<m)return 1;
        return 0;
    }
};