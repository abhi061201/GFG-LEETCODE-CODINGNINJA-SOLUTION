class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n= tri.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0; i<n;i++)
        {
            dp[n-1][i] = tri[n-1][i];
        }
        for(int row=n-2; row>=0 ; row--)
        {
            for(int col=0; col<=row; col++)
            {
                int down=1e9, dr= 1e9;
                down = dp[row+1][col];
                dr= dp[row+1][col+1];
                dp[row][col]=tri[row][col]+ min(down, dr);
            }
        }
        
        return dp[0][0];
    }
    int go(int row, int col, vector<vector<int>>& tri, vector<vector<int>>&dp)
    {
        if(row==tri.size())return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int down=1e9, dr= 1e9;
        down = go(row+1, col, tri,dp);
        dr= go(row+1, col+1, tri,dp);
        return dp[row][col]=tri[row][col]+ min(down, dr);
    }
};