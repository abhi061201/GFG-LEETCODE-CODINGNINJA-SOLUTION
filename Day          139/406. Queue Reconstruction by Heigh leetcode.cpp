class Solution {
public:
        
   static bool comp(vector<int>&a, vector<int>&b){
        return a[0]==b[0] ? a[1]<b[1]: a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),comp); 
        int n= people.size();
        vector<pair<int,int>>v(n,{-1,-1});
        vector<int>vis(n,0);
        for(auto it : people){
            int a= it[0];
            int b= it[1];
         int count= b;
           for(int i=0 ; i<n ; i++){
              
              if(count==0 && !vis[i]){
                  vis[i]=1;
                  v[i]= {a,b};
                  break;
              }
             
              else if( v[i].first==-1 ||v[i].first >= a ){
                  count--;
              }
               
           }
            
        }
        vector<vector<int>>ans;
        for(auto it : v)ans.push_back({it.first, it.second});
        return ans;
        
    }
};
