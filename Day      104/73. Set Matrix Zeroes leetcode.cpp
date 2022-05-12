class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
        
        int row0=0,col0=0, n= mt.size(),m=mt[0].size();
        for(int j=0 ; j<m ; j++){
           if(mt[0][j]==0)row0=1;   
        }
        for(int i=1; i<n ; i++){
            if(mt[i][0]==0)col0=1;
            for(int j=1 ; j<m ; j++ ){
                // if(mt[0][j]==0)row0=1;
                if(!mt[i][j]){
                    mt[0][j]=0,mt[i][0]=0; 
                }
                
            }
        }

        int x=0;
        if(mt[0][0]==0){x=1;}
        
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m; j++){
                if(!mt[i][0] || !mt[0][j]){
                    mt[i][j]=0;
                }
            }
        }
        if( row0==1 ||x==1){
        for(int i=0 ; i<m ; i++){
            mt[0][i]=0;
        }
            }
        if(col0|| x==1){
        for(int i=0 ; i<n ; i++){
            mt[i][0]=0;
        }
            }
        
        
    }
};
