class Solution {
public:
    vector<int> getRow(int n) {
        
        vector<int>v(n+1,0);
        v[0]=1;
        for(int i=1 ;i<=n ;i++ ){
            
            for(int j=n ;j>=1 ;j--){
                 v[j]= v[j]+v[j-1];
                
            }
            
        }
        return v;
        
        
    }
};
