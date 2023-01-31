class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size()  , m= mat[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<int>>dp(n, vector<int>(m,1e9));
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m ; j++)
            {
                if(mat[i][j]==0)
                {
                    dp[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int curdist= q.front().first;
            int i= q.front().second.first;
            int j= q.front().second.second;
            q.pop();
            
            
            for(int k=0; k<4; k++)
            {
                int x= i+dr[k][0];
                int y= j+dr[k][1];
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y])
                {
                    vis[x][y]=1;
                    dp[x][y]= min(1+dp[i][j] , dp[x][y]);
                    q.push({curdist+1,{x,y}});
                }
            }
            
        }
        return dp;
    }
};