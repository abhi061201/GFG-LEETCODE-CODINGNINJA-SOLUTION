class Solution {
public:
    int numDecodings(string s) {
        
        if(s.length()==2 && s[0]==0)return 0;
        vector<int>dp(s.length()+1,-1);
        return go(0, s.length(), s,dp);
        
        
    }
    int go(int i , int e, string s,vector<int>&dp){
        
        if(i>e)return 0;
        if(i==e)return 1;
        if(dp[i]!=-1)return dp[i];
        int temp1=0,temp2=0;
        
        if(s[i]!='0')temp1= go(i+1,e,s,dp);
        if(s[i]>'0' && i+1<e && (s[i]=='1' or (s[i]=='2' and s[i+1]<='6')))temp2= go(i+2, e,s,dp);
        
       
        return dp[i]= temp1+temp2;
        
        
    }
};
