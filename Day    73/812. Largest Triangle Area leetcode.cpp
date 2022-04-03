class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        
        int n= points.size();
        double ans=0;
        for(int i=0 ; i<n-2 ; i++){
            for(int j= i+1 ; j<n-1 ; j++){
                double a= dist(points[i], points[j]);
                
                for(int k=j+1 ; k<n ; k++){
                    double b= dist(points[i],points[k]);
                    double c= dist(points[j],points[k]);
                    double s= (a+b+c)/2.0;
                    ans= max(ans,area(s,a,b,c) );
                }
            }
        }
        return ans;
    }
    double dist(vector<int>&p1, vector<int>&p2){
        
        double x= 1.0, y=1.0;
        x= (p1[0]-p2[0])*(p1[0]-p2[0]);
        y= (p1[1]-p2[1])*(p1[1]-p2[1]);
        return sqrt(x+y);
    }
    double area( double s, double a , double b, double c){
        
        double x= s*(s-a)*(s-b)*(s-c);
        return sqrt(x);;
    }
    
    
};
