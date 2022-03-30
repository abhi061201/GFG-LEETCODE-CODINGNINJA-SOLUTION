class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int t) {
        int m=mt.size(), n= mt[0].size();
        
        for(int i=0 ; i<m ; i++ ){
            for(int j= 0; j<n ; j++){
                if(mt[i][j]==t)return 1;
                
            }
        }
        return 0;
    }
};
