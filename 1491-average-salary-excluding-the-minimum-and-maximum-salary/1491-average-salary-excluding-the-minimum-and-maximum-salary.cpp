class Solution {
public:
    double average(vector<int>& salary) {
        double sum=accumulate(salary.begin(), salary.end(),0);
        int maxi= *max_element(salary.begin(), salary.end());
        int mini= *min_element(salary.begin(), salary.end());
        return (sum-maxi-mini)/(salary.size()-2);
        
        
    }
};