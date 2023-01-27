//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        solve(mat);
        return mat;
    }
    int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int n, m;
    void solve(vector<vector<char>>& board) {
        n = board.size(), m= board[0].size();
        
        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O')dfs(i, 0, board);
            if(board[i][m-1]=='O')dfs(i, m-1, board);
            
        }
        
        for(int j=0; j<m; j++)
        {
            if(board[0][j]=='O')dfs(0, j, board);
            if(board[n-1][j]=='O')dfs(n-1, j, board);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m; j++)
            {
                
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='1')board[i][j]='O';
                
                
            }
        }
        
    }
    void dfs(int i, int j,vector<vector<char>>& board )
    {
        board[i][j]='1';
        for(int k=0; k<4; k++)
        {
            int x= i+dr[k][0];
            int y= j+dr[k][1];
            if(x>=0 && x<n && y>=0 && y<m && board[x][y]=='O')dfs(x,y,board);
        }
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends