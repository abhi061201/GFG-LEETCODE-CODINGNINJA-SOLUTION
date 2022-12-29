//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& tri) {
        
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i=0; i<n;i++)
        {
            dp[n-1][i] = tri[n-1][i];
        }
        for(int row=n-2; row>=0 ; row--)
        {
            for(int col=0; col<=row; col++)
            {
                int down=1e9, dr= 1e9;
                down = dp[row+1][col];
                dr= dp[row+1][col+1];
                dp[row][col]=tri[row][col]+ min(down, dr);
            }
        }
        
        return dp[0][0];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends