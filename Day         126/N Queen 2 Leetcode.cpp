class Solution {
public:
    int totalNQueens(int n) {
        
        vector <vector <string >>ans;
        vector<string >board;
         string s(n,'.');
        for(int i=0 ; i<n ; i++){
           board .push_back(s);
        }
        
        go(0,ans,n,board);
        return ans.size();
        
        
        
    }
    void go(int col, vector <vector <string >>&ans,int n, vector<string>board ){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0 ; row<n; row++){
            if(issafe(row, col, board)){
                board[row][col]='Q';
                go(col+1, ans,n,board);
                board[row][col]='.';
            }
        }
    }
    bool issafe(int row, int col, vector<string>&board){
        int x=row,y=col;
        int n= board.size();
        // checking upper left diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        
        row=x;
        col=y;
        
        // checking left lower diagonal
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        
        row=x;
        col=y;
        
        //checking left horizontal
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        return true;
        
    }
};
