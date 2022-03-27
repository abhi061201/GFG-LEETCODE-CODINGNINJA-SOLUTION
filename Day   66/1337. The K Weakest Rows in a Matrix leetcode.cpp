class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n= mat.size();
        int m= mat[0].size();
        vector<pair<int, int>>v;
        for(int i=0 ; i<n ; i++){
            int c_1=0;
            for(int j=0 ;j<m ; j++ ){
                if(mat[i][j]==1)c_1++;
            }
            v.push_back({c_1, i});
        }
        sort(v.begin(), v.end());
        
        vector<int> ans;
        for(int i=0 ; i<k ; i++){
            ans.push_back(v[i].second);
        }
        return ans; 
    }
};
