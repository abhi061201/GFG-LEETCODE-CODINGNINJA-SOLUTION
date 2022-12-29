//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod= 1e9+7;
    int dr[2][2]= {{0,-1},{-1,0}};
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        if(grid[n-1][m-1] == 1)return 0;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return go(n-1, m-1, grid,dp);
    }
    int go(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)return 1;
        if(grid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long int left=0, up=0;
        if(i-1>=0) left= go(i-1, j, grid,dp);
        if(j-1>=0) up = go(i, j-1, grid,dp);
        
        return dp[i][j]= (left%mod+up%mod)%mod;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends