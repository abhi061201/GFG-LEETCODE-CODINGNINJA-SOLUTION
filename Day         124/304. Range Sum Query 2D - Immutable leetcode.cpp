class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
       int n= matrix.size(), m= matrix[0].size();
        
        // vector<vector<int>>temp(n+1, vector<int>(m+1, 0));
        // for first row prefix sum
        for(int i=1 ; i<m ; i++)matrix[0][i]+=matrix[0][i-1];
        
        // for firrst column prefix sum
        for(int j=1 ; j<n ; j++)matrix[j][0]+=matrix[j-1][0];
        
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                matrix[i][j]+= matrix[i-1][j]+matrix[i][j-1] - matrix[i-1][j-1];
                
            }
        }
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<m ; j++){
//                 temp[i+1][j+1]= matrix[i][j];
//             }
            
//         }
        pref= matrix;
        
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans=pref[r2][c2];
        
        if(r1>0)ans-=pref[r1-1][c2];
        if(c1>0)ans-=pref[r2][c1-1];
        if(r1>0 && c1>0)ans+=pref[r1-1][c1-1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
