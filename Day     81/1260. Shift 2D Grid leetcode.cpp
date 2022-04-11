class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m =grid[0].size();
        vector<vector<int>>ans(n, vector<int>(m));
        if(k==m*n)return grid;
        vector<int>v;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                v.push_back(grid[i][j]);
            }
        }
        vector<int>temp =shift(v, k);
        int c=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans[i][j]=temp[c]; 
                c++;
            }
        }
        return ans;
        
    }
    vector<int> shift(vector<int>&v, int k){
        int n= v.size();
        vector<int>temp(n);
        for(int i=0 ; i<n ; i++){
            temp[(i+k)%n]= v[i];
        }
        return temp;
    }
};
