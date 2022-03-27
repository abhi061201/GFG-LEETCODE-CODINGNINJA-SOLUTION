class Solution {
public:
    int minDistance(string w1, string w2) {
        
        int n= w1.length();
        int m= w2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return go(w1, w2,n-1, m-1, dp);     
    }
    
    int go(string w1, string w2, int i, int j, vector<vector<int>>&dp){
        
        if(j<0)return i+1;
        if(i<0)return j+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j])return go(w1, w2, i-1, j-1,dp);
        
        
        int ins= 1+go(w1, w2, i, j-1,dp);
        int repl= 1+go(w1, w2, i-1, j-1,dp);
        int del= 1+ go(w1, w2, i-1,j,dp);
        
        return dp[i][j]=min({ins, del, repl});
        
    }
};
