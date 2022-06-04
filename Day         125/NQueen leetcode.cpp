class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        vector<string>board(n);
        // vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
        
        go(0,board,ans,n);
        return ans;
        
    }
    void go(int col, vector<string>&board, vector<vector<string>>&ans,int n ){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0 ; row<n ; row++){
            if(ispossible(row,col,board,n)){
                board[row][col]='Q';
                go(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    bool ispossible(int row, int col, vector<string>board,int n){
        
        int x=row ,y=col;
        // checking left horizontal
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        col=y;
        // checking upper left diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=x;
        col=y;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;col--;
        }
        
        return true;
        
    }
};
