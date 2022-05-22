class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        if(sp.size()==2)return 1;
        int n= sp.size();
       long double m=LONG_MIN;
        int count=0;
        sort(sp.begin(), sp.end());
       
        for(int i=0 ; i<n-1 ; i++){
            long double x= sp[i+1][0]-sp[i][0];
             long double y= sp[i+1][1]-sp[i][1];
            long double temp=y/x;
            if(temp!=m){
                count++;
            }
            m=temp;
        }
        return count;
    }
};
