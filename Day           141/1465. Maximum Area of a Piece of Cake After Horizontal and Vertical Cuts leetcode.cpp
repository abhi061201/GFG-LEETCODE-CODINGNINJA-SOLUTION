#define M 1000000007
#define ll long long int
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        
        hori.push_back(h); 
        
        verti.push_back(w); 
        sort(hori.begin(), hori.end()); 
        sort(verti.begin(), verti.end()); 
        
         ll mhori=0;
        for(int i=0,prev=0; i<hori.size(); i++){
            mhori= max(mhori, (long long int)hori[i]-prev);
            prev= hori[i];
            
        }
        ll mverti= 0; 
        for(int i=0,prev=0 ; i<verti.size(); i++){
            mverti= max(mverti, (long long int)verti[i]-prev);
            prev= verti[i];
        }
        ll ans= (int)(mverti % M * mhori%M)%M;
        // cout<<ans;
        return ans;
        
    }
};
