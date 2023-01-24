class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n= board.size();
        queue<int>q;
        q.push(1);
        vector<vector<int>>vis(n, vector<int>(n,0));
        vis[n-1][0]=1;
        int steps=0;
        while(!q.empty()){
            int size= q.size();
            for(int m=0 ; m<size; m++){
            int cur= q.front();
            q.pop();
            if(cur==n*n)return steps;
            
            for(int k=1 ;k<=6 ; k++){
                if(cur+k>n*n)break;
                pair<int,int> p= findcoor(cur+k,n);
                if(vis[p.first][p.second]==1)continue;
                vis[p.first][p.second]=1;
                if(board[p.first][p.second]==-1)q.push(cur+k);
                else q.push(board[p.first][p.second]);
            }}
            steps++;
        }
        return -1;
      
    }
    pair<int,int> findcoor(int cur, int n){
        int r= n-1-(cur-1)/n;
        int c= (cur-1)%n;
        if(r%2==n%2){
            return {r,n-1-c};
            
        }
        return {r,c};
    }
};