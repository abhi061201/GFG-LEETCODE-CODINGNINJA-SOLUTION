class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
        int n = coor.size();
        int xdiff=coor[0][0]- coor[1][0];
        int ydiff= coor[0][1]- coor[1][1];
        for(int i=1; i<n-1; i++)
        {
            if((coor[i][0]- coor[i+1][0])*ydiff!=(coor[i][1]-coor[i+1][1])* xdiff )return 0;
        }
        return 1;
    }
};