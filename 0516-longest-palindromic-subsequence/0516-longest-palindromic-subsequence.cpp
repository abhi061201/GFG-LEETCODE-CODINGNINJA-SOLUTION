class Solution {
public:
    string s;
    int longestPalindromeSubseq(string S) {
        s=S;
        int n= s.length();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return go(0,n-1,dp);
        
    }
    int go( int i,int j, vector<vector<int>>&dp){
        if(i>j )return 0;
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=2+go(i+1,j-1,dp);
        return dp[i][j]=max(go(i+1,j,dp), go(i,j-1,dp));
    }
};