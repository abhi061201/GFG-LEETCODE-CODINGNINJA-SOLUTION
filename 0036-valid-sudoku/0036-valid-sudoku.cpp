class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')continue;
                for(int col=0; col<9; col++)
                {
                    if(col!= j && board[i][col]==board[i][j])return 0;
                }
                // for col
                for(int row=0; row<9; row++)
                {
                    if(i!=row && board[row][j]==board[i][j])return 0;
                }
                
                // for box
                for(int k=0; k<9; k++)
                {
                    int r= 3*(i/3) + k/3;
                    int c= 3*(j/3)+ k%3;
                    if(board[i][j]== board[r][c]){
                        if(i!=r && c!= j)return 0;
                    }
                }
            }
        }
        return 1;
    }
};