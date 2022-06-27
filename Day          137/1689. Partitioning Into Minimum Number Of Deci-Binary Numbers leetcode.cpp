class Solution {
public:
    int minPartitions(string s) {
        
        int maxi=0;
        // findindg the max value of int into the string
        //since in the ans no. we can take only max 1 
        //therefore the max digit in string s is the ans.
        for(auto it : s ){
            int temp= it-'0';
            maxi= max(maxi, temp);
        }
        return maxi;
    }
};
