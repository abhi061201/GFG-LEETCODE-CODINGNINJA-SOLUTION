class Solution {
public:
    
    vector<double> answer;
    map<string,vector<pair<string,double>>>graph;
    vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& queries) {
        
        for(int i=0 ; i<eqn.size() ; i++){
            string so= eqn[i][0];
            string de= eqn[i][1];
            
            graph[so].push_back({de,val[i]});
            graph[de].push_back({so,(double)1/val[i]});
        }
        
        for(auto query: queries){
            string so= query[0];
            string de= query[1];
            double ans= -1.0F,pro= 1.0F;
            set<string> vis;
            dfs(so,de,vis,ans,pro);
            answer.push_back(ans);
                
        }
        return answer;
    }
    bool dfs(string so, string de, set<string>&vis, double &ans, double pro  ){
        
        if(so==de && graph.find(de) != graph.end()){
            ans=pro;
            return true;
        }
        vis.insert(so);
        for(auto it : graph[so]){
            string dest= it.first;
            double val=it.second;
            
            if(vis.find(dest)==vis.end() ){
                if(dfs(dest,de,vis,ans, pro*val))return true;
            }
            
        }
        return false;
        
    }
    
};
