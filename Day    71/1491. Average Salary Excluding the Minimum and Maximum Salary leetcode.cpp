class Solution {
public:
    double average(vector<int>& salary) {
        
        
        int n= salary.size();
        double sum=0;
        sort(salary.begin(), salary.end());
        for(int i=1 ; i<n-1 ; i++){
            sum+=salary[i];
        }
        return sum/(n-2);
    }
};
