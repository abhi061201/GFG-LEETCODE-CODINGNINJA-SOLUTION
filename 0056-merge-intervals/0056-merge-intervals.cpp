class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        
        int x, y;
        for(int i=0; i<n;i++)
        {
            x= intervals[i][0];
            y= intervals[i][1];
            while(i<n && y >= intervals[i][0] )
            {
                y = max(y, intervals[i][1]);
                i++;
            }
            i--;
            ans.push_back({x, y});
        }
        return ans;
    }
};