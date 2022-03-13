class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        
        
        vector<vector<int>>dp;
         vector<int >temp(1,1);
        dp.push_back(temp);
        for(int i=2 ;i<=n ;i++ ){
            vector<int >v(i,0);
            temp.push_back(0);
            v[0]=1;
            for(int j=i-1 ;j>=1 ;j--){
                 v[j]= temp[j]+temp[j-1];
              }
            temp=v;
            dp.push_back(v);
            
        }
        return dp;
        
        
    }

};
