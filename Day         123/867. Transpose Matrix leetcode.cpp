class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        
        vector<vector<int>>dp;
        for(int col=0 ; col<m ; col++){
            vector<int>temp;
            for(int row=0 ; row<n ; row++){
                temp.push_back(matrix[row][col]);
            }
            dp.push_back(temp);
        }
        return dp;
    }
};
