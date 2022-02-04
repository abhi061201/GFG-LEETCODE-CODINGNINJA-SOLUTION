// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void print(vector<vector<char>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
                cout<<grid[i][j]<<" , ";
                
            }
            cout<<"\n";
        }
        cout<<"-----------------\n";
    }
    void bfs(int i,int j,vector<vector<char>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>>q;  
          q.push({i,j});
        while(!q.empty()){
            int curi=q.front().first;
            int curj=q.front().second;
            q.pop();
            int dr[8][2]= {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
            for(int k=0 ;k<8 ;k++){
                int nbrx= curi+dr[k][0];
                int nbry= curj+dr[k][1];
                
                if(nbrx>=0 && nbrx <n && nbry>=0 && nbry<m &&grid[nbrx][nbry]=='1' ){
                    grid[nbrx][nbry]='0';
                    q.push({nbrx,nbry});
                    
                }
            }
           
            
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        int count=0;
      
        
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
                    // print(grid);
                }
                
            }
        }
        return count;
       
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
