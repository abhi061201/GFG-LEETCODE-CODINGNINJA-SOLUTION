class Solution {
public:
    int minDistance(string w1, string w2) {
        int n= w1.length();
        int m= w2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        int lcs= go(n-1, m-1, w1,w2,dp);
        return n+m- 2*lcs;
        
    }
    int go(int i, int j, string w1, string w2,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j])return dp[i][j]= 1+go(i-1,j-1,w1,w2,dp);
        return dp[i][j]=max(go(i-1,j,w1,w2,dp), go(i,j-1,w1,w2,dp));
        
    }
};
