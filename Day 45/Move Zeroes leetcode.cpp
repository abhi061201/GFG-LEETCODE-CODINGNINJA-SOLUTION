class Solution {
public:
    void moveZeroes(vector<int>&v) {
        
        int n= v.size();
        int begin=0;
       for(int i=0 ;i<n ;i++){
           if(v[i]!=0){
               v[begin++]=v[i];
           }
       }
        while(begin<n){
            v[begin++]=0;
        }
        
    }
};
