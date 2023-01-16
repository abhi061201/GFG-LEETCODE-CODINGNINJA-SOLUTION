class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;  
        int x, y, n = intervals.size();
        for(int i=0; i<n;i++)
        {
            x= intervals[i][0];
            y= intervals[i][1];
            while(i<n && y>= intervals[i][0] )
            {
                y= max(y, intervals[i][1]);
                i++;
            }
            i--;
            ans.push_back({x,y});
        }
        return ans;
    }
};