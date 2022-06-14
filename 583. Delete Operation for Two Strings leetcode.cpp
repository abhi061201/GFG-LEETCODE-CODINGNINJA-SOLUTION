class Solution {
public:
    string s1,s2;
    int minDistance(string S1, string S2) {
        s1=S1;
        s2=S2;
        int n= S1.length();
        int m= S2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       int ans= go(n-1,m-1,dp);
       return n+m-2*ans;
        
    }
    int go(int i,int j, vector<vector<int>>&dp){
        if(i<0 || j<0 )return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]= 1+go(i-1,j-1,dp);
         else return  dp[i][j]=max(go(i-1,j,dp),go(i,j-1,dp));
    }
};
