class Solution {
public:
    int minDistance(string s1, string s2) {
        
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
        return go(s1,s2,0,0,dp);
        
    }
    int go(string s1, string s2,int i, int j, vector<vector<int>>&dp){
        
        if(i==s1.length())return s2.length()-j;
        if(j==s2.length())return s1.length()-i;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]=go(s1,s2,i+1,j+1,dp);
        
        int insert = 1 + go(s1,s2,i,j+1,dp);
        int remove = 1 + go(s1,s2,i+1,j,dp);
        int replace = 1 + go(s1,s2,i+1,j+1,dp); 
        
        return dp[i][j]=min(insert,min(remove,replace));
    }
};
