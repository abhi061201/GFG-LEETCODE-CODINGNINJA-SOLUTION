class Solution {
public:
    string s1, s2;
    int longestCommonSubsequence(string se1, string se2) {
        s1=se1;
        s2=se2;
        int n= s1.length();
        int m= s2.length();
        int ans=0;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        ans= go(n-1,m-1,dp);
        return ans;
    }
    int go (int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+go(i-1, j-1,dp);
        return dp[i][j]=max(go(i-1,j,dp), go(i,j-1,dp));
    }
};
