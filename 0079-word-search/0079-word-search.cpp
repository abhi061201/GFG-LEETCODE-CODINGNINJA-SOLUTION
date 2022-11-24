class Solution {
public:
    int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == word[0] && wordfound(1,i,j,board,word))return 1;
                
            }
        }
        return false;
    }
    
    bool wordfound(int ind, int i, int j, vector<vector<char>>&board, string &word)
    {
        if(ind==word.size())return 1;
        char c= board[i][j];
        board[i][j]='*';
        for(int k=0; k<4; k++)
        {
            int curi= i+dr[k][0];
            int curj= j+dr[k][1];
            if(curi>=0 && curi<n && curj>=0 && curj<m && word[ind] == board[curi][curj])
            {
                if(wordfound(ind+1, curi, curj, board, word))return 1;
            }
        }
        board[i][j]=c;
        return 0;
    }
};