class Solution {
public:
    vector<int> intersection(vector<int>& v1, vector<int>& v2) {
        
        vector<int>v;
        set<int>s1;
        set<int >s2;
        
        for(auto it : v1){
            s1.insert(it);
            
        }
        
         for(auto it : v2){
            s2.insert(it);
        }
        
        for(auto it = s1.begin() ; it!=s1.end() ;it++){
            
            int temp= *it;
            cout<<temp<<" , ";
            if(s2.find(temp)!=s2.end())v.push_back(temp);
            
        }
        cout<<"\n";
        return v;
        
    }
};
