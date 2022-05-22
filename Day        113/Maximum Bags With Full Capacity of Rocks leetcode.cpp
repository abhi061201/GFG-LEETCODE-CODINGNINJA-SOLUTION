class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int k) {
        int count=0,n=c.size();
        
//         vector<pair<int , int>>v;
//         for(int i=0 ; i<n ; i++){
//             v.push_back({r[i], c[i]});
//         }
//         sort(v.begin(), v.end());
        
//         for(int i=n ; i>=0 ; i--){
//             int fi= v[i].first;
//             int se= v[i].second;
//             if(fi==se)count++;
//         }
        vector<int>diff(n);
        for(int i=0 ; i<n ; i++){
            diff[i]= c[i]-r[i];
            
        }
        sort(diff.begin(), diff.end());
        for(auto it : diff){
            if(it==0)count++;
            if(k>=it && it>0){
                k-=it;
                count++;
            }
        }
        return count;
    }
}; 
