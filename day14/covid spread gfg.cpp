// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
        //code here
     int n= grid.size();
     int m= grid[0].size();
     
     queue<pair<int,int>> q;
     for(int i=0 ;i<n ; i++){
         for(int j=0 ;j<m ;j++){
             if(grid[i][j]==2){
                 q.push({i,j});
             }
         }
     }
     
     int time=0;
     int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
     
     while(!q.empty()){
         
         int size= q.size();
        //  cout<<size <<" \n";
         for(int i=0 ;i<size; i++){
             
             int x= q.front().first;
             int y= q.front().second;
             
             q.pop();
             for(int k=0 ;k<4 ;k++){
                 int dx= dr[k][0];
                 int dy= dr[k][1];
                 int nbrx= dx+x;
                 int nbry= dy+y;
                 
    if(nbrx>=0 && nbrx<n && nbry>=0 && nbry<m && grid[nbrx][nbry]==1){
        grid[nbrx][nbry]=2;
        q.push({nbrx,nbry});
        
    }
             }
             
         }
         
        if(!q.empty())time++; 
     }
     
     
    for(int i=0 ;i<n ; i++){
         for(int j=0 ;j<m ;j++){
             if(grid[i][j]==1){
                 time=-1;
                 break;
             }
         }
     }
     
     
       
       return time; 
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
