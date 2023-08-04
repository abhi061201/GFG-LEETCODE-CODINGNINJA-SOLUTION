class Solution {
public:
    vector<vector<string>>ans;
    int n;
    vector<vector<string>> solveNQueens(int N) {
        n=N;
        string s(n,'.');
        
        vector<string>board(n,s);
        // cout<<'hii';
        go(0,board);
        
        return ans;
    }
    void go(int i,vector<string>&board)
    {
        if(i==n)
        {
            // cout<<"hii";
            ans.push_back(board);
            return ;
        }
        
        // place a queen
        
        
        for(int j=0; j<n;j++)
        {
            // check we can place queen at this pos or not
            if(canPlace(i,j,board))
            {
                board[i][j]='Q';
                go(i+1,board );
                board[i][j]='.';
                // cout<<"hi";
            }
        }
        
        
    }
    bool canPlace(int i, int j, vector<string>&board)
    {
        // for up column
        
        for(int r=i; r>=0; r--)
        {
            if(board[r][j]=='Q')return false;
        }
        
        // for up right diagonal
        
        for(int r=i,c=j; r>=0 && c<n ; r--,c++)
        {
            
                if(board[r][c]=='Q')return false;
            
        }
        
        // for up left diagonal
        for(int r=i, c=j; r>=0 && c>=0 ; r--, c--)
        {
            
                if(board[r][c]=='Q')return false;
            
        }
        // cout<<"hii";
        return true;
    }
};