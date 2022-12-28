class Solution {
public:
    
    
    //since hme kabhi na kabhi particular row m se niklna pdega ..
    // similarly for column to ..hm ending pos ki direction m hi nikle phir to accha rhega
    // agr hum opp direction m jayenge to extra cost lgegi
    
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& rc, vector<int>& cc) {
        int cost=0;
        if(sp[0]==hp[0] && hp[1]== sp[1])return 0;
        // abhi hum row m pahuchna chahte h 
        int row_incr= hp[0] > sp[0] ? 1: -1;
        
        for(int i= sp[0] ; i!= hp[0] ; i+= row_incr)
        {
            cost+= rc[i+row_incr];
        }
        
        int col_incr= hp[1] > sp[1] ? 1: -1;
        
        for(int i= sp[1] ; i!= hp[1] ; i+= col_incr)
        {
            cost+= cc[i+col_incr];
        }
        return cost;
    }
};