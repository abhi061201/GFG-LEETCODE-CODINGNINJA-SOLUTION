class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n= costs.size();
        vector<pair<int, int>>atob;
        int i=0;
        for(auto it : costs){
            
            atob.push_back({it[0]-it[1],i});
            i++;
            
            
        }
        sort(atob.begin(), atob.end());
        int sum=0;
        for(int i=0 ; i<n/2 ; i++){
            sum+=costs[atob[i].second][0];
        }
        for(int i=n/2 ; i<n ; i++){
            sum+=costs[atob[i].second][1];
        }
        return sum;
    }
};
