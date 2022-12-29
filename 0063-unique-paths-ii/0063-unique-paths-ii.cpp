class Solution {
public:
    int dr[2][2]={{-1,0},{0,-1}};
    int n,m;
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        n = og.size();
        m= og[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        if(og[n-1][m-1]==1)return 0;
        return go(n-1, m-1, og,dp);
    }
    int go(int i, int j,vector<vector<int>>& og,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=0; k<2; k++)
        {
            int curi = i+dr[k][0];
            int curj = j+dr[k][1];
            
            if(isValid(curi, curj) && og[curi][curj]==0)
            {
                og[curi][curj]=1;
                ans+= go(curi, curj, og,dp);
                og[curi][curj]=0;
            }
            
        }
        return dp[i][j]= ans;
            
    }
    bool isValid(int i, int j)
    {
        if(i>=0  && i<n && j>=0 && j<m)return 1;
        return 0;
    }
};