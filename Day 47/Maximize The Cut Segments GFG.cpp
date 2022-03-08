// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
   int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        vector<int>dp(n+1,-1);
        int temp=go(n, v , dp);
        return  temp>0 ?temp:0;
        
    }
    
    int go(int n , vector<int>v,  vector<int>&dp){
        
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        int ans= INT_MIN;
       for(int i=0 ;i<3 ;i++){
            
            int count=0;
            count=1+ go(n-v[i],v,dp);
            ans= max(ans,count);
            
        }
        return dp[n]=ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
