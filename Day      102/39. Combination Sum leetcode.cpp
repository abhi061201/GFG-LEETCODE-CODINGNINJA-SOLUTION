class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& k, int n) {
        
        vector<vector<int>>ans;
        vector<int> temp;
        
        fun(0,k,n , ans, temp );
            return ans;
    }
    
    void fun( int start,vector<int>& k, int n, vector<vector<int>>&ans, vector<int>temp ){
        if( n<0)return ;
        
       if( n==0 )ans.push_back(temp);
        
        for(int i=start ; i<k.size(); i++){
            temp.push_back(k[i]);
            fun(i,k , n-k[i], ans,temp);
            temp.pop_back();
            
            
        }
        
        
    }
    
};
