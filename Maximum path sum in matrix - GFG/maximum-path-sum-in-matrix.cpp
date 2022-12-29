//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n;
    int maximumPath(int N, vector<vector<int>> mat)
    {
        int ans=0;
        n= N;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++)
        {
            ans= max(ans, go(0,i,mat, dp));
            
        }
        return ans;
        
    }
    int go(int i, int j, vector<vector<int>>&mat,vector<vector<int>>&dp)
    {
        if(i==mat.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=0, down=0, right=0;
        if(j-1 >=0 )left= go(i+1, j-1, mat,dp);
        down= go(i+1, j, mat,dp);
        if(j+1 < n)right= go(i+1, j+1, mat,dp);
        return dp[i][j]=mat[i][j]+ max({left, down, right});
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends