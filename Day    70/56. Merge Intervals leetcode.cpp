class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n= inter.size();
        if(n==1)return inter;
        vector<vector<int>>ans;
//         priority_queue<pair<int, int>> pq;
//         for(auto it : inter ){
//             pq.push({it[0], it[1]});
//         }
        
//         int curi=pq.top().first;
//         int curj=pq.top().second;
//         pq.pop();
        
//         while(!pq.empty()){
//          while(pq.top().first <curj){
//         int x=pq.top().first;
//         int y=pq.top().second;
//          pq.pop();
//              curj= y;
//          }
//             vector<int>temp;
//             temp.push_back(curi);
//             temp.push_back(curj);
//             ans.push_back(temp);
//         }
        
        vector<pair<int, int>>v;
        for(auto it : inter){
            int x=it[0];
            int y= it[1];
            v.push_back({x,y});
        }
        sort(v.begin(), v.end());
        
        for(int i=0 ; i<n; i++){
            int x=v[i].first;
            int y= v[i].second;
            for(int j=i; j<n ; j++){
                if(y>=v[j].first){
                    y= max(y,v[j].second);
                    i=j;
                }
            }
            vector<int>temp;
            temp.push_back(x);
            temp.push_back(y);
            ans.push_back(temp);
        }
        
        
        return ans;
    }
};
