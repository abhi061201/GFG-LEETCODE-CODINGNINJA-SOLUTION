// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int step=0;
       int n= grid.size();
       int m= grid[0].size();
       for(int i=0 ;i<n ;i++){
           for(int j=0 ;j<m ;j++){
               if(grid[i][j]=='X'){
                   step++;
                   bfs(i,j,grid);
                //   print(grid,n,m);
               }
           }
       }
       return step;
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid){
        int n= grid.size();
       int m= grid[0].size();
       queue<pair<int,int>> q;
       q.push({i,j});
       int dr[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
       while(!q.empty()){
           int x= q.front().first;
           int y= q.front().second;
           q.pop();
           for(int k=0 ;k<4 ;k++){
               int dx= dr[k][0];
               int dy= dr[k][1];
               int nbrx= dx+x;
               int nbry= dy+y;
               if(nbrx>=0 && nbrx <n && nbry>=0 && nbry <m &&grid[nbrx][nbry]=='X'){
                   grid[nbrx][nbry]='O';
                   q.push({nbrx,nbry});
               }
           }
           
       }
       
    }
    void print(vector<vector<char>>& grid, int n , int m){
        
        for(int i=0 ;i<n ;i++){
           for(int j=0 ;j<m ;j++){
               cout<<grid[i][j]<<" , ";
               }
               cout<<"\n";
           }
        cout<< "---END---\n";
        }
           
    
    
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
