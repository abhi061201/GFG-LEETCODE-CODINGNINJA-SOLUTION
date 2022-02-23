#define pii pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& n, vector<int>& m, int k) {
        
        int n_s= n.size();
        int m_s= m.size();
     priority_queue<pii>pq;
        int pair=0;
        for(int i=0 ;i<n_s ;i++){
            for(int j=0 ;j<m_s ;j++){
               
                int sum= n[i]+m[j];
                pq.push({sum,{n[i],m[j]}});
                if(k<pq.size()){
                    if(sum>=pq.top().first){
                        pq.pop();
                        break;
                    }
                    pq.pop();
                }
            }
        }
     
        vector<vector<int>>v; 
        while(!pq.empty()){
            int temp1= pq.top().second.first;
            int temp2= pq.top().second.second;
            pq.pop();
            vector<int>temp;
            temp.push_back(temp1);
            temp.push_back(temp2);
            v.push_back(temp);
                
        }
        // sort(v.begin(),v.end());
        return v;
    }
};
