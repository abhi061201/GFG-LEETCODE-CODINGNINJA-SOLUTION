class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        
        int totalgas= accumulate(gas.begin() , gas.end(),0);
        int totalcost= accumulate(cost.begin(), cost.end(),0);
        if(totalcost>totalgas)return -1;
        int curfuel=0, start=0;
        for(int i=0; i<n ;i++)
        {
            curfuel+= gas[i]-cost[i];
            if(curfuel<0){
                start=i+1; 
                curfuel=0;
            }
        }
        
        return start;
    }
};