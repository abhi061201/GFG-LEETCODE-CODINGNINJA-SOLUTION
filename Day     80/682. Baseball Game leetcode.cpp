class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int>v;
        for(auto it : ops){
            
            if(it=="D"){
                int last= v[v.size()-1]*2;
                v.push_back(last);
                
            }
            else if(it=="+"){
                  int last= v[v.size()-1];
                  int ls= v[v.size()-2];
                v.push_back(last+ls);
            }
            
            else if(it=="C"){
                v.pop_back();
                
                
            }
            else {
                v.push_back(stoi(it));
            }
            
            
        }
        int temp=0;
        for(auto it : v){
            temp+=it;
        }
        
        return temp;
    }
};
