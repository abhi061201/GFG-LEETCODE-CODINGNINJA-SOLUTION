class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
      map<char, int> mp;
        int n= s.length();
        
        for(int i=0 ; i<n ; i++){
            
            mp[s[i]]=i;
            // mp.insert({s[i],i});
            
        }
       
//         for(auto it = mp.begin() ; it!=mp.end() ; it++){
            
//            cout<<it->first<<" , "<<it->second<<"\n";
//         }
        
        int prev=-1;
        int maxi= 0;
        for(int i=0 ; i<n ;i++){
            maxi=max(maxi,mp[s[i]]);
            if(maxi==i){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
            
            
        }
        
        return ans;
    }
};
