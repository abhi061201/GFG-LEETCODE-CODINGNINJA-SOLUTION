class Solution {
public:
    int minSteps(int n) {
        set<pair<int, int>>s;
       return go(1,0, n,s); 
    }
    
    
    int go(int sc, int cl, int n,set<pair<int, int>>&s){
        // sc: total char on screen
        // cl : total char on clipboard
        // we take step because of infinite loop 
        // go(1,0,5) in paste operation it will again call go(1, 0, 5);
        // due to which it also prevents the repeated calss so no dp required;
        
        if(sc==n)return 0;
        if(sc>n)return 1e8;
        
        if(s.find({sc,cl})!=s.end()){
            return 1e8;
                                     }
        s.insert({sc,cl});
        int copy= 1+ go(sc, sc, n,s);
        int paste= 1+ go(sc+cl,cl,n,s);
        
        return min(copy , paste);
        
        
    }
};
