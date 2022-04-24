class UndergroundSystem {
public:
    map<int, pair<string, int>> in;
    map<pair<string, string>,vector<int>>out;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
    
       in[id]={stationName, t };
        
    }
    
    void checkOut(int id, string stationName, int t) {
       pair<string,int> p= in[id];
        out[{p.first,stationName}].push_back(t-p.second);
        
      
    }
    
    double getAverageTime(string sS, string eS) {
        vector<int>v= out[{sS, eS}];
        double count=0;
        for(auto it : v ){
            count+=it;
        }
        double ans= count/v.size();
        return ans;
       
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
