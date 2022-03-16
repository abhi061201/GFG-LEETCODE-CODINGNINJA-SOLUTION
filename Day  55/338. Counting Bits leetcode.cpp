class Solution {
public:
    vector<int> countBits(int n) {
        
        
             vector<int>ans;
        ans.push_back(0);
       for(int i=1 ; i<=n ;i++ ){
            vector<int> v;
           go(i,v);
           int count=0;
           for(auto it : v){
               if(it==1)count++;
           }
           ans.push_back(count);
           
       }
       
        
        return ans;
        
    }
    
    void go(int n, vector<int>&v)
    {
        if(n==0)return ;
        go(n/2,v);
        int x= n%2;
        v.push_back(x);
    }
};
