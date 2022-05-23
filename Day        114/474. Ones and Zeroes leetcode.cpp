class Solution {
public:int maxi=0;
    int findMaxForm(vector<string>& str, int x, int y) {
        
        int n= str.size();
        
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1,-1)));
           return  go(n-1,str,x,y,dp);
        
    }
    int go(int i, vector<string>&str,int x, int y , vector<vector<vector<int>>>&dp){
        if(i<0)return INT_MIN;
        if(dp[i][x][y]!=-1)return dp[i][x][y];
        int a=0,b=0,take=INT_MIN,n_take=0;
         calc(str[i], a,b);
        if(i==0 ){
           if(a<=x && b<=y) return 1;
            return 0;
        }
       
        
        n_take= go(i-1, str,x,y,dp);
        if(x>=a && y>=b )take= 1+go(i-1, str,x-a,y-b,dp);
        return dp[i][x][y]=max(take,n_take);
    }
    
    void calc(string s, int &a, int &b){
        int n= s.length();
        for(auto it : s){
            if(it=='0')a++;
        }
        b=n-a;
    }
};
