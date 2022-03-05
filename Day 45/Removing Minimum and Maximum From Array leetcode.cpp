class Solution {
public:
    int minimumDeletions(vector<int>& v) {
        int n= v.size();
        vector<int>temp;
        for(auto it : v){
            temp.push_back(it);
        }
        sort(temp.begin(), temp.end());
        
        int min_ele=temp[0];
        int max_ele= temp[n-1];
        int min_ele_ind=0;
        int max_ele_ind= 0;
        for(int i=0 ;i<n ;i++){
            if(v[i]==temp[0])min_ele_ind=i;
            if(v[i]==temp[n-1])max_ele_ind=i;
        }
      int x= min_ele_ind;
       int y=   max_ele_ind;
        x++;y++;
        int ff= max(x,y);
        int bf= n-x+1+y;
        int fb= x+n-y+1;
        int bb= max(n-x+1,n-y+1);
       if(n==1)return 1;
      return  min(bb,min(fb,min(ff,bf)));
        
    }
};
