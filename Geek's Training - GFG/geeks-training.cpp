//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  // 0- running
  // 1- fighting
  // 2- practice
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n+1, vector<int>(3,0));
        
        for(int i=1; i<=n; i++)
        {
            for(int act=0; act<3 ;act++)
            {
                int run=0, fight=0, practice=0;
                if(act!=0)run= points[i-1][0]+ dp[i-1][0];
                if(act!=1) fight= points[i-1][1]+dp[i-1][1];
                if(act!=2) practice= points[i-1][2]+ dp[i-1][2];
                
                dp[i][act]= max({run, fight, practice});
            }
        }
        
        return max({dp[n][0], dp[n][1], dp[n][2]});
    }
    
    int go(int i, vector<vector<int>>& points, int act,vector<vector<int>>&dp)
    {
        if(i<0)return 0;
        int run=0, fight=0, practice=0;
        
        if(dp[i][act]!=-1)return dp[i][act];
        if(act!=0)run= points[i][0]+ go(i-1, points, 0,dp);
        if(act!=1) fight= points[i][1]+ go(i-1, points, 1,dp);
        if(act!=2) practice= points[i][2]+ go(i-1, points, 2,dp);
        
        return dp[i][act]= max({run, fight, practice});
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends