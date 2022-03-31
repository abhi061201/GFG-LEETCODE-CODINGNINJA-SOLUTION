class Solution {
public:
    void rotate(vector<vector<int>>& mt) {
        int n= mt.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                swap(mt[i][j], mt[j][i]);
            }
        }
        
        for(int i=0 ; i<n ; i++){
            reverse(mt[i].begin(), mt[i].end());
        }
    }
};
