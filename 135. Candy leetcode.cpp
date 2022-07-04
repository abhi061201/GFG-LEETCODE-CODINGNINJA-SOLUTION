class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n= ratings.size(); 
        vector<int>ltor(n,1);
        vector<int>rtol(n,1);
        for(int i=1 ; i<n ; i++){
            if(ratings[i]> ratings[i-1]){
                ltor[i]= 1+ltor[i-1];
            }
        }
        for(int i=n-2 ; i>=0 ; i--){
            if(ratings[i] > ratings[i+1]){
                rtol[i]= 1+rtol[i+1];
            }
        }
        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans+= max(ltor[i], rtol[i]);
        }
        return ans;
    }
};
