class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m= text2.length();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return go(n-1, m-1, text1, text2,dp);
        
    }
    int go(int i, int j, string &t1, string &t2,vector<vector<int>>&dp)
    {
        if(i<0|| j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i]==t2[j])return dp[i][j]= 1+ go(i-1, j-1, t1, t2,dp);
        
        int l=go(i, j-1, t1, t2,dp);
        int r= go(i-1, j, t1, t2,dp);
        return dp[i][j]=max(l,r);
    }
};
