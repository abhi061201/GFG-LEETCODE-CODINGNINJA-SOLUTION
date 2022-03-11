class Solution {
public:
    int maxProfit(vector<int>& v) {
 int n=v.size();
        
        vector<int>left(n);
        vector<int>right(n);
        int mini=v[0];
        left[0]=0;
        for(int i=1 ; i<n ;i++){
            
            mini= min(mini, v[i]);
            left[i]= max(left[i-1], v[i]-mini);
            
            
        }
        int maxi=v[n-1];
        right[n-1]=0;
        for(int i=n-2 ; i>=0 ;i--){
            maxi= max(maxi, v[i]);
            right[i]= max(right[i+1], maxi-v[i]);
          
        }
       
        
        int ans=max(right[0], left[n-1]);
        for(int i=0 ; i<n-1 ;i++){
            ans= max(ans,left[i]+ right[i+1]);
        }
        
        return ans;
    }
};
