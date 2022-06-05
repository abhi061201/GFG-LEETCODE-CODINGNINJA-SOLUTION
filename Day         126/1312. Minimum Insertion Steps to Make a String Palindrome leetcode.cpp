class Solution {
public:
    int minInsertions(string s) {
        int n= s.length();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return go(0,n-1,s,dp);
        
    }
    int go(int i, int j, string &s, vector<vector<int>>&dp){
        
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]= go(i+1, j-1, s,dp);
        
        return dp[i][j]=1+min( go(i+1,j,s,dp),go(i,j-1,s,dp));
        
    }
};
