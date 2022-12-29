//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n, m;
    int dr[3]= {-1,0,1};
    int solve(int N, int M, vector<vector<int>>& grid) {
        n=N, m=M;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1) ) );
        return go(0, 0, m-1, grid,dp);
    }
    int go(int i, int j1, int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp )
    {
        if(i==n)return 0;
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans=0;
        // dr[k] = change in col of robo 1
        // robot ki ek move k liye doosre k paas 3 choice h to total choice= 3*3=9;
        for(int k=0; k<3; k++)
        {
            int curj1= dr[k]+j1;
            if(!valid(curj1))continue;
            for(int l= 0; l<3; l++)
            {
                int curj2= dr[l]+j2;
                if(!valid(curj2))continue;
                if(j1== j2)ans= max(ans, grid[i][j1] + go(i+1, curj1,curj2,grid ,dp));
                else ans= max(ans, grid[i][j1]+ grid[i][j2]+ go(i+1, curj1, curj2, grid,dp));
                
            }
        }
        return dp[i][j1][j2]= ans;
        
    }
    bool valid(int col)
    {
        if(col>=0 && col<m)return 1;
        return 0;
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends