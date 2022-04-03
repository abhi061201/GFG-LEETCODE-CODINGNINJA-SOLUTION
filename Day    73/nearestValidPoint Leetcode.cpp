class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        
        int n= points.size();
        int mini=INT_MAX;
        int index=n-1;
        int flag=0;
        for(int i=n-1 ; i>=0 ; i--){
            if(points[i][0]==x || points[i][1]==y){
                flag=1;
            int dist= abs(points[i][0]-x)+abs(points[i][1]-y);
            if(dist<=mini){
                mini=dist;
                index=i;
            }
            }
        }
        if(!flag)return -1;
        return index;
    }
};
