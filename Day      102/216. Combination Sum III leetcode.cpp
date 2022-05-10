class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        fun(1, k,n,ans, temp);
        
        return ans;
    }
    
    void fun(int start, int k, int n , vector<vector<int>>&ans,vector<int> temp ){
        
        if(k<0 || n<0)return ;
        if(k==0 && n==0){
            ans.push_back(temp);
        }        
        for(int i=start; i<=9 ; i++){
            temp.push_back(i);
            fun(i+1, k-1 , n-i , ans,temp);
            temp.pop_back();// backtrack
            
        }
        
    }
};
