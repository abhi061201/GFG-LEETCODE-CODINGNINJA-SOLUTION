class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans=0;
        vector<int>temp= heights;
        sort(temp.begin(), temp.end());
        for(int i=1 ; i<=heights.size(); i++)
        {
            if(temp[i-1]!= heights[i-1])ans++;
        }
        return ans;
    }
};