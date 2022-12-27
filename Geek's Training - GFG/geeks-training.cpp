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
        vector<vector<int>>dp(n, vector<int>(4,-1));
        return go(n-1, points, 3,dp);
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