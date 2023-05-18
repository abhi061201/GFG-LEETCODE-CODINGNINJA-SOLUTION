class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        
        vector<int>indegree(n,0), ans;
        for(auto it: edges)indegree[it[1]]++;
        
        for(int i=0; i<n;i++)if(!indegree[i])ans.push_back(i);
        return ans;
        
    }
};