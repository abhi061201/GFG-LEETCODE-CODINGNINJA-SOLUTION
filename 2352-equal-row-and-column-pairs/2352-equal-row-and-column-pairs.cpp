class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int count= 0;
        for(int i=0 ; i<n ; i++){
            vector<int>ri= grid[i];
            count+=check(ri, grid,n);
        }
        return count;
        
    }
    int check(vector<int>&ri,vector<vector<int>>& grid,int n ){
        int count=0;
        for(int j=0; j<n ; j++){
            bool flag=1;
            for(int i=0;i<n ; i++){
                if(ri[i]!=grid[i][j])flag=false;
            }
            if(flag)count++;
        }
        return count;
    }
};