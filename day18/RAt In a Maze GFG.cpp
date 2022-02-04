// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void dfs(int i, int j ,vector<vector<int>> &m,vector<vector <int>>&vis,string path,int n,vector<string>&ans,int dr[4][2])
    {
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }
        string st= "DLRU";
        for(int k=0 ;k<4 ;k++){
            int nbrx=i+dr[k][0];
            int nbry=j+dr[k][1];
            
            if(nbrx<n && nbrx>=0 && nbry<n && nbry>=0 &&m[nbrx][nbry]==1 && vis[nbrx][nbry]==0){
                vis[i][j]=1;
                dfs(nbrx,nbry,m,vis,path+st[k] ,n,ans,dr);
                vis[i][j]=0;
            }
        }
        
    }    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector <int>>vis(n, vector<int>(n,0));
        vector <string> ans;
        string path="";
        int dr[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
        if(m[0][0]==1){
            dfs(0,0,m,vis,path,n,ans,dr);
        }
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
