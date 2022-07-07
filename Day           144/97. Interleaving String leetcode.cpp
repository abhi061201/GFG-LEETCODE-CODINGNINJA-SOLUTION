class Solution {
public:
    string s1,s2,s3;
    bool isInterleave(string S1, string S2, string S3) {
        s1=S1;s2=S2;s3=S3;
        int n= s1.length(), m= s2.length(), x= s3.length();
        if(n+m !=x)return false;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1, vector<int>(x+1, -1)));
        
        return go(0,0,0,dp);
        
        
    }
    bool go(int i, int j, int k,vector<vector<vector<int>>>&dp){
        if(k==s3.length() && i==s1.length()&& j==s2.length())return true;
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        
        bool t1=false,t2=false;
        if(s1[i]==s3[k])t1= go(i+1, j, k+1,dp);
        if(s2[j]==s3[k])t2= go(i, j+1, k+1,dp);
        return dp[i][j][k]=t1 or t2;
    }
};
