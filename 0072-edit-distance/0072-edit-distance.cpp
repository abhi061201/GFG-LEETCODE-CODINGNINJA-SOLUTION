class Solution {
public:
    int minDistance(string word1, string word2) {
        int n= word1.length(), m= word2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return go(0,0,word1, word2, dp);
    }
    int go(int i,int j,string &s1, string s2,vector<vector<int>>&dp)
    {
        if(i== s1.length())return s2.length()-j;
        if(j== s2.length())return s1.length()-i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return go(i+1, j+1, s1, s2,dp);
        
        int insert= 1+ go(i, j+1, s1,s2,dp);
        int del= 1+ go(i+1, j+1, s1, s2,dp);
        int repla= 1+ go(i+1, j, s1, s2,dp);
        return dp[i][j]= min({insert, del, repla});
    }
};