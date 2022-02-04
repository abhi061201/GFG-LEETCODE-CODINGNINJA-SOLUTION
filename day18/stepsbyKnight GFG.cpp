// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
	{
	    // Code here
	    int ki,kj,ti,tj;
	    ki= K[0];
	    kj= K[1];
	    ti= T[0];
	    tj= T[1];
	    int step=0;
	    
	    
	    vector<vector<int>> vis(N+1,vector<int>(N+1,0));
	    queue<pair<int,int>> q;
	    q.push({ki,kj});
	    while(!q.empty()){
	        
	        int size= q.size();
	        for(int i=0 ;i<size; i++){
	        int x= q.front().first;
	        int y= q.front().second;
	        q.pop();
	        vis[x][y]=1;
	       if(x==ti && y==tj)return step;
	       
	       int dr[8][2]= {{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
	       for(int k=0;k<8 ;k++){
	           int nbrx=x+dr[k][0]; 
	           int nbry=y+dr[k][1];
	           
	           if(nbrx>=1 && nbrx<=N &&nbry>=1 && nbry<=N && !vis[nbrx][nbry] )
	           {
	             vis[nbrx][nbry]=1;
	             q.push({nbrx,nbry});
	           }
	       }
	       
	    }
	    step++;
	    
	    }
	    return step;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
