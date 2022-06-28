class Solution {
public:
    int minDeletions(string s) {
        
        map<char ,int>mp; 
        for(auto it: s){
            if(mp.find(it)!=mp.end()){
                mp[it]++;
            }
            else mp[it]=1;
        }
        unordered_set<int> se;
        int count=0;
        for(auto it : mp){
            int x= it.second;
           
            if(se.find(x)==se.end()){
                se.insert(x);
            }
            else{
                
                while(x!=0 && se.find(x)!=se.end()){
                    count++;
                    x--;
                }
                if(x!=0)se.insert(x);
                
            }
            
        }
        return count;
        
    }
};
