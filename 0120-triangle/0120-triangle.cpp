class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n= tri.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return go(0, 0, tri, dp);
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