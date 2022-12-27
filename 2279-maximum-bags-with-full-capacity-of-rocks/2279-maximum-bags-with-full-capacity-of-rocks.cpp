class p{
    public:
    int a, b;
    
};
class Solution {
public:
    
    static bool customSort(p &obj1 , p &obj2)
    {
        return abs(obj1.a-obj1.b) < abs(obj2.a -obj2.b);
    }
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        
        int n = c.size();
        vector<p> v(n);
        for(int i=0; i<n;i++)
        {
            v[i].a= c[i];
            v[i].b= r[i];
        }
        
        sort(v.begin(), v.end(), customSort);
        int ans=0;
        for(int i=0; i<n ;i++)
        {
            if(ar>=0)
            {
                int diff= v[i].a- v[i].b;
                if(ar>= diff)
                {
                    ar-= diff;
                    v[i].b+= diff;
                }
                if(v[i].a== v[i].b)ans++;
                
                
            }
            // cout<<v[i].a<<" : "<<v[i].b<<endl; 
        }
        
        
        return ans;
        
    }
};