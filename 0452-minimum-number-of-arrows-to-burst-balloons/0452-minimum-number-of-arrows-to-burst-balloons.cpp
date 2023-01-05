class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n= points.size();
        int count=1, st=points[0][0], en=points[0][1];
        
        for(auto it: points)
        {
            if(isoverlap(st, en, it[0], it[1]))
            {
                st= max(st, it[0]);
                en= min(en, it[1]);
            }
            else 
            {
                count++;
                st= it[0];
                en= it[1];
            }
             // cout<<st<<" , "<<en<<" : "<<count<<endl;
        }
        return count;
    }
    bool isoverlap(int a1, int b1, int a2, int b2)
    {
        if(a1>=a2 && a1 <=b2)return 1;
        if(b1>=a2 && b1 <=b2)return 1;
        if(a1<=a2 && b1 >=b2)return 1;
        return 0;
        
    }
};